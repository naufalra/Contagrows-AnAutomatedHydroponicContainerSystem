void suhu_air () {
  suhu.requestTemperatures();
  tempc = suhu.getTempCByIndex(0);
  Serial.print("suhu air =");
  Serial.println(tempc);

}
