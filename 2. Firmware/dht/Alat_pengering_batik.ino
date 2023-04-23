#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <virtuabotixRTC.h>

#define DHTPIN1 3
#define DHTPIN2 4
#define DHTTYPE DHT22
#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 9
#define button1 8
#define button2 9
#define button3 10
#define button4 11
#define pompa 14
#define radiator 15
#define resetdht 5
#define blower 16
#define bounce 10



LiquidCrystal_I2C lcd(0x20, 128, 64);
LiquidCrystal_I2C lcd2(0x26 , 20, 4);
DHT dht1 (DHTPIN1, DHTTYPE);
DHT dht2 (DHTPIN2, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature suhu(&oneWire);
Servo servoinlet, servooutlet;
virtuabotixRTC myRTC(22, 23, 24);//urut

float tempc, t1, t2, h1, h2, rata2t, rata2h;
float tempair;
int varair = 40,  varvent = 90, varruang = 55;
int jam, menit, kondisi = 0, servo = 0, timer = 0, truang = 0;
int jammon, menmon, detmon = 0, timemon = 0;
int jamstat = 0, menstat = 2;
String notif = "[START]", notif1 = "Sistem Mati";


void setup() {
  Serial.begin(115200);
  pinMode(1, HIGH);
  suhu.begin();
  dht1.begin();
  dht2.begin();
  lcd.begin();
  lcd2.begin();
  servoinlet.attach(7);
  servooutlet.attach(6);
  lcd.backlight();
  lcd2.backlight();
  // seconds, minutes, hours, day of the week, day of the month, month, year
  //    myRTC.setDS1302Time(00, 5, 14, 6, 29, 7, 2021);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(pompa, OUTPUT);
  pinMode(radiator, OUTPUT);
  pinMode(resetdht, OUTPUT);
  pinMode(blower, OUTPUT);
  digitalWrite(pompa, HIGH);
  digitalWrite(radiator, HIGH);
  digitalWrite(blower, HIGH);
  servoinlet.write(0);
  delay(1000);
  servooutlet.write(1);
  delay(500);
  servooutlet.write(0);
  delay(500);
  servoinlet.detach();
  servooutlet.detach();

}


void loop() {


  lcd.clear();
  lcd2.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alat Pengering Batik");
  lcd.setCursor(4, 1);
  lcd.print("PKM-PI 2021");
  lcd.setCursor(8, 2);
  lcd.print("UGM");
  lcd.setCursor(0, 3);
  lcd.print(notif);
  lcd.setCursor(11, 3);
  lcd.print("[Setting]");


  //LCD Monitor
  lcd2.setCursor(0, 0);
  lcd2.print("Suhu Air    =");
  lcd2.print(tempc);
  lcd2.print((char)223);
  lcd2.print("C");
  lcd2.setCursor(0, 1);
  lcd2.print("Suhu Ruangan=");
  lcd2.print(rata2t);
  lcd2.print((char)223);
  lcd2.print("C");
  lcd2.setCursor(0, 2);
  lcd2.print("Kelembaban  =");
  lcd2.print(rata2h);
  lcd2.print(" %");
  
  lcd2.setCursor(4, 3);
  lcd2.print(notif1);

  semua();
  suhu_air();
  myRTC.updateTime();
  dht();

  if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    Serial.print("button dipencet");
    lcd.clear();
    menusetting();
  }

  if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    digitalWrite(1, LOW);
    delay(1000);
    digitalWrite(1, HIGH);
    delay(1000);
  }

  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    mulai();
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print("Please Wait..");
  }

  if (tempc > varair+2 and kondisi == 1)  {
    notif1 = "Sistem Hidup";
    notif = "[RUN]";
    digitalWrite(pompa, LOW);
    digitalWrite(radiator, LOW);

    if (timer == 1) {
      menit = myRTC.minutes + menit;
      jam = myRTC.hours + jam;
      timer = 0;
      timemon = 1;
    }
    if (jam == myRTC.hours and menit == myRTC.minutes) {
      jam = 0;
      menit = 0;
      kondisi = 0;
    }
    else if (rata2h > varvent) {

      if (servo == 0) {

        exhaust_nyala();
        servo = 1;
        Serial.print("exhaust nyala");
      }
    }


    else if (rata2h < varvent - 2) {

      if (servo == 1) {
        exhaust_mati();
        servo = 0;
        Serial.print("exhaust mati");
      }

    }
    if (rata2t > varruang and truang == 0) {
      kondisi = 0;
      truang = 1;
      if (servo == 1) {
        exhaust_mati();
        servo = 0;

      }
    }

  }

  if (rata2t < (varruang - 5) and tempc > varair and truang == 1) {
    kondisi = 1;
    truang = 0;
  }

  if (tempc < varair or kondisi == 0  ) {
    digitalWrite(pompa, HIGH);
    digitalWrite(radiator, HIGH);
    if (servo == 1) {
      exhaust_mati();
      servo = 0;
    }
    Serial.print("sistem mati");
    notif = "[START]";
    notif1 = "Sistem Mati";
  }
  if (isnan(h1) or isnan(t1) or isnan(h2) or isnan(t2)) {
    digitalWrite(resetdht, LOW);
    delay(2000);
    digitalWrite(resetdht, HIGH);
    Serial.println("RESET!!!!!!!");
  }

  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);



  delay(1000);
}
