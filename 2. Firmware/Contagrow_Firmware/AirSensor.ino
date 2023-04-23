const int DO = 8;
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;
float bmeTemp, bmeHumid, bmePressure, bmeAltitude;
float sensor_volt;
float RS_gas;
float ratio;
int sensorValue;
float R0 = 0.10;

void getairSensor()
{
  getDht();
  getBme();
  getCO();
}

void getCO()
{
  sensorValue = analogRead(COPIN);
  sensor_volt = ((float)sensorValue / 1024) * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // Depend on RL on yor module
  ratio = RS_gas / R0; // ratio = RS/R0
  //------------------------------------------------------------/
  //  Serial.print("sensor_volt = ");
  //  Serial.println(sensor_volt);
  //  Serial.print("RS_ratio = ");
  //  Serial.println(RS_gas);
  //  Serial.print("Rs/R0 = ");
  //  Serial.println(ratio);
  //  Serial.print("\n\n");
  //  delay(10);
}


//=============================================================================== DHT 22 ======================================================================
#include <DHT.h>;
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
float dhtHumidity;  //Stores humidity value
float dhtTemperature; //Stores temperature value

void getDht()
{
  dhtHumidity = dht.readHumidity();
  dhtTemperature = dht.readTemperature();
  //  Serial.print("Humidity: ");
  //  Serial.print(dhtHumidity);
  //  Serial.print(" %, Temp: ");
  //  Serial.print(dhtTemperature);
  //  Serial.println(" Celsius");
}

void dhtDebug()
{
  getDht();
  Serial.print("Humidity: ");
  Serial.print(dhtHumidity);
  Serial.print(" %, Temp: ");
  Serial.print(dhtTemperature);
  Serial.println(" Celsius");
}




//=============================================================================== BME ======================================================================
void getBme()
{
  bmeTemp = bme.readTemperature();
  bmeHumid = bme.readHumidity();
  bmePressure = bme.readPressure() / 100.0F;
  bmeAltitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  //  Serial.print("Temperature = ");
  //  Serial.print(bmeTemp);
  //  Serial.println("*C");
  //
  //  Serial.print("Pressure = ");
  //  Serial.print(bmeHumid);
  //  Serial.println("hPa");
  //  delay(500);
}

void bmeDebug()
{
  getBme();
  Serial.print("Temperature = ");
  Serial.print(bmeTemp);
  Serial.println("*C");

  Serial.print("Pressure = ");
  Serial.print(bmeHumid);
  Serial.println("hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bmePressure);
  Serial.println("m");

  Serial.print("Humidity = ");
  Serial.print(bmeAltitude);
  Serial.println("%");
  Serial.println();
  //  delay(1000);
}
unsigned long lastTime;

void airsensorDebug() //sampling every 10 second
{

  //  if (millis() - lastTime > 10000)
  //  {
  //    getairSensor();
  //    Serial.print(bmeTemp); Serial.print("\t");
  //    Serial.print(bmeHumid); Serial.print("\t");
  //    Serial.print(dhtTemperature); Serial.print("\t");
  //    Serial.print(dhtHumidity); Serial.print("\t");
  //    Serial.print(ratio); Serial.println("\t");
  //    lastTime = millis(); //Update the timer
  //  }
  //  else
  //  {
  //    Serial.print(bmeTemp); Serial.print("\t");
  //    Serial.print(bmeHumid); Serial.print("\t");
  //    Serial.print(dhtTemperature); Serial.print("\t");
  //    Serial.print(dhtHumidity); Serial.print("\t");
  //    Serial.print(ratio); Serial.println("\t");
  //  }

  //  getairSensor();
  //  Serial.print(bmeTemp); Serial.print("\t");
  //  Serial.print(bmeHumid); Serial.print("\t");
  //  Serial.print(dhtTemperature); Serial.print("\t");
  //  Serial.print(dhtHumidity); Serial.print("\t");
  //  Serial.print(ratio); Serial.println("\t");

  const unsigned long fiveMinutes = 1 * 60 * 1000UL;
  static unsigned long lastSampleTime = 0 - fiveMinutes;  // initialize such that a reading is due the first time through loop()

  unsigned long now = millis();
  if (now - lastSampleTime >= fiveMinutes)
  {
    lastSampleTime += fiveMinutes;
    getairSensor();
    Serial.print(bmeTemp); Serial.print("\t");
    Serial.print(bmeHumid); Serial.print("\t");
    Serial.print(dhtTemperature); Serial.print("\t");
    Serial.print(dhtHumidity); Serial.print("\t");
    Serial.print(ratio); Serial.println("\t");
  }
}
