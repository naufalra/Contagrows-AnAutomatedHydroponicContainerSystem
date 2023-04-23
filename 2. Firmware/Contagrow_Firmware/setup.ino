void first_setup()
{
  lcd.begin(20, 4);
  lcd.init();
  Serial.begin(115200);
  dht.begin();
  Wire.begin();

  pinMode(SOIL1, INPUT);
  pinMode(SOIL2, INPUT);
  pinMode(SOIL3, INPUT);
  pinMode(SOIL4, INPUT);
  pinMode(SOIL5, INPUT);
  pinMode(SOIL6, INPUT);
  pinMode(SOIL7, INPUT);
  pinMode(SOIL8, INPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);
  
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  splashScreen();
  delay(2000);
}
