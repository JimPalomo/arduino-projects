/*
 * Blinking LED 
 * 
 * Directly on Arduino & on Board
 * 
 * Jim Palomo
 */

void setup() {
  // set pin 13 as output
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // turns LED on
  delay(1000);            // wait 1 sec
  digitalWrite(13, LOW);  // turn LED off
  delay(1000);            // wait 1 sec
}
