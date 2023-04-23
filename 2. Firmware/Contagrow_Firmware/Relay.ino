/*
   Relay 1 is Fan
   Relay 2 is Light
   Relay 3 is Pump
*/

#define  Mati HIGH
#define  Menyala LOW

void relayOff()
{
  for (int x = 0; x < 10; x++)
    digitalWrite(x, Mati);
  delay(10);
}

void relayOn()
{
  for (int x = 0; x < 10; x++)
    digitalWrite(x, Menyala);
  delay(10);
}


void manualcontrol() {

}
