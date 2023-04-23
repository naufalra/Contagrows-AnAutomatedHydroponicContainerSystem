int btn1, btn2, btn3, btn4;

void buttonDebug()
{
  btn1 = digitalRead(button1);
  btn2 = digitalRead(button2);
  btn3 = digitalRead(button3);
  btn4 = digitalRead(button4);

  Serial.print(btn1); Serial.print(", ");
  Serial.print(btn2); Serial.print(", ");
  Serial.print(btn3); Serial.print(", ");
  Serial.print(btn4);
  Serial.println();
}
