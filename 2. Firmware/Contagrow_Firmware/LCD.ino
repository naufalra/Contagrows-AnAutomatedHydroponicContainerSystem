void splashScreen()
{

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2, 1); lcd.print("   Contagrow   ");
  lcd.setCursor(3, 2); lcd.print("Container Farm");
  createCustomCharacters();
  printFrame();
}

//unsigned long currentMillis = millis();
//unsigned long previousMillis = 0; // millis() returns an unsigned long.
//unsigned long lastTime;

void monitoring()
{
  lcd.backlight();
  lcd.clear();
  
  getairSensor();

  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(dhtTemperature);
  lcd.print((char)223);
  lcd.print("C | ");
  lcd.setCursor(13, 0);
  lcd.print(dhtHumidity);
  lcd.print("%");

  lcd.setCursor(0, 2);
  lcd.print("CO: ");
  lcd.setCursor(6, 1);
  lcd.print(ratio);
  lcd.print(" %");

  lcd.setCursor(0, 3);
  lcd.print("Suhu Panel=");
  lcd.print(bmeTemp);
  lcd.print((char)223);
  lcd.print("C");
}

void menuSetting()
{

}


byte verticalLine[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte char2[8] = {
  B00000,
  B00000,
  B00000,
  B11100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte char1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00111,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

byte char3[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte char4[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b11100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void printFrame()
{
  lcd.setCursor(1, 0);
  lcd.print("------------------");
  lcd.setCursor(1, 3);
  lcd.print("------------------");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(0, 2);
  lcd.write(byte(0));
  lcd.setCursor(19, 1);
  lcd.write(byte(0));
  lcd.setCursor(19, 2);
  lcd.write(byte(0));
  lcd.setCursor(0, 0);
  lcd.write(byte(1));
  lcd.setCursor(19, 0);
  lcd.write(byte(2));
  lcd.setCursor(0, 3);
  lcd.write(byte(3));
  lcd.setCursor(19, 3);
  lcd.write(byte(4));
}

void createCustomCharacters()
{
  lcd.createChar(0, verticalLine);
  lcd.createChar(1, char1);
  lcd.createChar(2, char2);
  lcd.createChar(3, char3);
  lcd.createChar(4, char4);
}
