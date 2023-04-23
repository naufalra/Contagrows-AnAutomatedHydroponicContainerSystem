void menusetting() {
panahair :
  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    lcd.clear();
    kondisi=1;
    timer=1;
    goto loop;
  }

  else if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    lcd.clear();
    varair--;
    if (varair < 20) {
      varair = 80;
    }
  }

  else if (digitalRead(button3) == LOW) {
    delay (bounce);
    while (digitalRead(button3) == LOW) {}
    lcd.clear();
    varair++;
    if (varair > 80) {
      varair = 40;
    }
  }
  else if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    lcd.clear();
    
    goto panahvent;
  }

  lcd.setCursor(0, 0);
  lcd.print("->setTemp Air  =");
  lcd.print(varair);
  lcd.setCursor(0, 1);
  lcd.print("  set ventilasi=");
  lcd.print(varvent);
  lcd.setCursor(0, 2);
  lcd.print("  set time     ");
  lcd.setCursor(0, 3);
  lcd.print("[BACK] [-][+] [NEXT]");
  goto panahair;

panahtime:
  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    lcd.clear();
    kondisi=1;
    timer=1;
    goto loop;
  }

  else if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    lcd.clear();
    goto setjam;
  }

  else if (digitalRead(button3) == LOW) {
    delay (bounce);
    while (digitalRead(button3) == LOW) {}
    lcd.clear();
    goto setjam;
  }
  else if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    lcd.clear();
    goto panahair;

  }
  lcd.setCursor(0, 0);
  lcd.print("  setTemp Air  =");
  lcd.print(varair);
  lcd.setCursor(0, 1);
  lcd.print("  set ventilasi=");
  lcd.print(varvent);
  lcd.setCursor(0, 2);
  lcd.print("->set time     ");
  lcd.setCursor(0, 3);
  lcd.print("[BACK]  [OKE] [NEXT]");
  goto panahtime;

panahvent:
  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    lcd.clear();
    kondisi=1;
    timer=1;
    goto loop;
  }

  else if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    lcd.clear();
    varvent--;
    if (varvent < 50) {
      varvent = 100;
    }

  }

  else if (digitalRead(button3) == LOW) {
    delay (bounce);
    while (digitalRead(button3) == LOW) {}
    lcd.clear();
    varvent++;
    if (varvent > 100) {
      varvent = 50;
    }

  }
  else if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    lcd.clear();
    goto panahtime;
  }

  lcd.setCursor(0, 0);
  lcd.print("  setTemp Air  =");
  lcd.print(varair);
  lcd.setCursor(0, 1);
  lcd.print("->set ventilasi=");
  lcd.print(varvent);
  lcd.setCursor(0, 2);
  lcd.print("  set time     ");
  lcd.setCursor(0, 3);
  lcd.print("[BACK] [-][+] [NEXT]");
  goto panahvent;
  
setjam:
  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    lcd.clear();
    jammon=jam; 
    menmon=menit; 
    detmon= 0;  
    Serial.print(jam);
    goto panahvent;
  }

  else if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    lcd.clear();
    jam--;
    if (jam <0) {
      jam = 24;
    }
  }

  else if (digitalRead(button3) == LOW) {
    delay (bounce);
    while (digitalRead(button3) == LOW) {}
    lcd.clear();
    jam++;
    if (jam>24  ) {
      jam = 0;
    }
  }
  else if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    lcd.clear();
    goto setmenit;

  }
  

  lcd.setCursor(0, 0);
  lcd.print("->set Hour  =");
  lcd.print(jam);
  lcd.setCursor(0, 1);
  lcd.print("  set minute=");
  lcd.print(menit);
  
  lcd.setCursor(0, 3);
  lcd.print("[BACK] [-][+] [NEXT]");
  goto setjam;

setmenit:
  if (digitalRead(button1) == LOW) {
    delay (bounce);
    while (digitalRead(button1) == LOW) {}
    lcd.clear();
    menmon=menit;
    jammon=jam;
    detmon=0;
    Serial.print(menit);
    goto panahvent;
  }

  else if (digitalRead(button2) == LOW) {
    delay (bounce);
    while (digitalRead(button2) == LOW) {}
    lcd.clear();
    menit--;
    if (menit <0) {
      menit = 59;
    }
  }

  else if (digitalRead(button3) == LOW) {
    delay (bounce);
    while (digitalRead(button3) == LOW) {}
    lcd.clear();
    menit++;
    if (menit>60) {
      menit = 0;
    }
  }
  else if (digitalRead(button4) == LOW) {
    delay (bounce);
    while (digitalRead(button4) == LOW) {}
    lcd.clear();
    goto setjam;

  }
  
  lcd.setCursor(0, 0);
  lcd.print("  set Hour  =");
  lcd.print(jam);
  lcd.setCursor(0, 1);
  lcd.print("->set minute=");
  lcd.print(menit);
 
  lcd.setCursor(0, 3);
  lcd.print("[BACK] [-][+] [NEXT]");
  
  goto setmenit;

loop:
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Please Wait..");
  delay(bounce);

}
