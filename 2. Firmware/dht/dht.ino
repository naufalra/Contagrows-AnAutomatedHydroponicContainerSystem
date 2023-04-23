//int h1;

//void semua() {
//  h1 = dht1.readHumidity();
//  t1 = dht1.readTemperature();
//  h2 = dht2.readHumidity() - 4;
//  t2 = dht2.readTemperature();
//  rata2t = (t1 + t2) / 2;
//  rata2h = (h1 + h2) / 2;
//  Serial.print("suhu udara rata - rata =");
//  Serial.println(rata2t);
//  Serial.print("kelembaban udara rata - rata =");
//  Serial.println(rata2h);
//}
//void dht() {
//  h1 = dht1.readHumidity();
//  t1 = dht1.readTemperature();
//  h2 = dht2.readHumidity() - 4;
//  t2 = dht2.readTemperature();
//  Serial.print("suhu dht 1 = ");
//  Serial.print(t1);
//  Serial.print("suhu dht 1 = ");
//  Serial.println(h1);
//  Serial.print("suhu dht 2 = ");
//  Serial.print(t2);
//  Serial.print("suhu dht 2 = ");
//  Serial.println(h2);
//
//}

//void exhaust_mati() {
//  //inlet exhaust mati
//  servoinlet.attach(7);
//  servoinlet.write(0);
//  delay(1000);
//
//  //outlet exhaust mati
//  servooutlet.attach(6);
//  servooutlet.write(0);
//  delay(1000);
//
//  digitalWrite(blower, HIGH);
//  servoinlet.detach();
//  servooutlet.detach();
//
//}
//void exhaust_nyala() {
//  //inlet udara masuk
//  servoinlet.attach(7);
//  servoinlet.write(110);
//  delay(1000);
//
//  //outlet udara keluar
//  servooutlet.attach(6);
//  servooutlet.write(110);
//  delay(1000);
//
//  digitalWrite(blower, LOW);
//
//  servoinlet.detach();
//  servooutlet.detach();
//}
