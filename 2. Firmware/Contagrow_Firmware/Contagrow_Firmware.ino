#include "Pin.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

//float sensor_volt;
//float RS_gas;
//float ratio;

const int rs = 12, rw = 1, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int Menu, Up, Down, Ok;
int lockMenu = 0, lockUp = 0, lockDown = 0, lockOk = 0;
int dis, sub = 0, mode = 0;

void setup() {
  first_setup();
//  relayon();
}
void loop() {
  //  relayon();
  relayOn();
  //  bmeDebug();
  //  int soil1 = analogRead(SOIL1);  // Read the analog value form sensor
  //  Serial.println(soil1);
  //  buttonDebug();
  monitoring();

  //  airsensorDebug();

  //  Menu = digitalRead(23);
  //  Up =   digitalRead(27);
  //  Down = digitalRead(25);
  //  Ok =   digitalRead(29);
  //  tampil();


  //  dhtDebug();
  //  getCO();
}

void tampil()
{
  if (Menu == 0 && lockMenu == 0) {
    lockMenu = 1;
  } if (Menu != 0 && lockMenu == 1) {
    lockMenu = 0;
    dis = 1;
  }
  if (Menu == 0 && lockMenu == 0) {
    lockMenu = 1;
  } if (Menu != 0 && lockMenu == 1 && dis > 1) {
    lcd.clear();
    lockMenu = 0;
    dis = 1;
  }

  if (dis == 1)
  {

    // tampilan awal//
    lcd.setCursor(0, 0); lcd.print("|    Contagrow    |");
    lcd.setCursor(1, 1); lcd.print("Monitoring             ");
    lcd.setCursor(1, 2); lcd.print("Setting             ");
    lcd.setCursor(1, 3); lcd.print("None             ");

    if (Down == 0 && lockDown == 0) {
      lockDown = 1; //turunkan Cursor ">"
    }
    if (Down != 0 && lockDown == 1) {
      lcd.clear();
      lockDown = 0;
      mode++;
    }

    if (Up == 0 && lockUp == 0) {
      lockUp = 1; //naikkan Cursor ">"
    }
    if (Up != 0 && lockUp == 1) {
      lcd.clear();
      lockUp = 0;
      mode--;
    }
    switch (mode)
    {
      //      case 0 : lcd.setCursor(0, 0); lcd.print(">"); break;
      case 1 : lcd.setCursor(0, 1); lcd.print(">"); break;
      case 2 : lcd.setCursor(0, 2); lcd.print(">"); break;
      case 3 : lcd.setCursor(0, 3); lcd.print(">"); break;
    }
    if (Ok == 0 && lockOk == 0) {
      lockOk = 1;
      mode = 0;
    }
    //    if (Ok != 0 && lockOk == 1 && mode == 0) {
    //      lockOk = 0;  // pilih menu 1
    //      dis = 2;
    //      lcd.clear();
    //    }
    if (Ok != 0 && lockOk == 1 && mode == 1) {
      lockOk = 0;  // pilih menu 2
      dis = 3;
      lcd.clear();
    }
    if (Ok != 0 && lockOk == 1 && mode == 2) {
      lockOk = 0;  // pilih menu 3
      dis = 4;
      lcd.clear();
    }
    if (Ok != 0 && lockOk == 1 && mode == 3) {
      lockOk = 0;  // pilih menu 4
      dis = 5;
      lcd.clear();
    }

    if (mode > 3 || mode < 0) mode = 0;

  }
  if (dis == 2)
  {
    if (sub == 0)
    {
      //      lcd.setCursor(0, 0); lcd.print("Monitoring             ");
      //      lcd.setCursor(1, 1); lcd.print("Sub Menu 1        ");
      //      lcd.setCursor(1, 2); lcd.print("Sub Menu 2        ");
      //      lcd.setCursor(1, 3); lcd.print("Sub Menu 3        ");
      monitoring();
      if (Down == 0 && lockDown == 0) {
        lockDown = 1; //turunkan Cursor ">"
      }
      if (Down != 0 && lockDown == 1) {
        lcd.clear();
        lockDown = 0;
        mode++;
      }

      if (Up == 0 && lockUp == 0) {
        lockUp = 1; //naikkan Cursor ">"
      }
      if (Up != 0 && lockUp == 1) {
        lcd.clear();
        lockUp = 0;
        mode--;
      }
      if (Ok != 0 && lockOk == 1 && mode == 0) {
        lockOk = 0;  // Isi submenu 1
        lcd.clear();
        sub = 1;
      }
      if (Ok != 0 && lockOk == 1 && mode == 1) {
        lockOk = 0;  // Isi submenu 2
        lcd.clear();
        sub = 2;
      }
      if (Ok != 0 && lockOk == 1 && mode == 2) {
        lockOk = 0;  // Isi submenu 3
        lcd.clear();
        sub = 3;
      }

      if (mode > 2 || mode < 0) mode = 0;
      {
        switch (mode)
        {

          case 1 : lcd.setCursor(0, 2); lcd.print(">"); break;
          case 2 : lcd.setCursor(0, 3); lcd.print(">"); break;
        }
      }
    }
  }

  if (dis == 3)
  { //menu kontrol manual
    lcd.setCursor(0, 0); lcd.print("Manual Control  ");
    lcd.setCursor(1, 1); lcd.print("Relay 1:        ");
    lcd.setCursor(1, 2); lcd.print("Relay 2:        ");
    lcd.setCursor(1, 3); lcd.print("Relay 3:        ");
  }

  if (dis == 4)
  {
    lcd.setCursor(0, 0); lcd.print("Menu 3             ");
    lcd.setCursor(1, 1); lcd.print("Sub Menu 1        ");
    lcd.setCursor(1, 2); lcd.print("Sub Menu 2        ");
    lcd.setCursor(1, 3); lcd.print("Sub Menu 3        ");
  }

  if (dis == 5)
  {
    lcd.setCursor(0, 0); lcd.print("Menu 4             ");
    lcd.setCursor(1, 1); lcd.print("Sub Menu 1        ");
    lcd.setCursor(1, 2); lcd.print("Sub Menu 2        ");
    lcd.setCursor(1, 3); lcd.print("Sub Menu 3        ");
  }
  //isi menu1////
  if (dis == 2 && sub == 1) {
    lcd.setCursor(0, 1);
    lcd.print(" Isi Sub Menu 1:::");
  }
  if (dis == 2 && sub == 2) {
    lcd.setCursor(0, 1);
    lcd.print(" Isi Sub Menu 2::");
  }
  if (dis == 2 && sub == 3) {
    lcd.setCursor(0, 1);
    lcd.print(" Isi Sub Menu 3:");
  }
}
