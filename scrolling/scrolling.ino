int timer = 100; // delay

/*
 * Scrolling
 * 
 * Sequencially turn the LEDs on/off
 * 
 * Jim Palomo
 */

void setup() {
  // initializes pins 2-8 as output
  for (int curPin = 2; curPin < 8; curPin++) {
    pinMode(curPin, OUTPUT);
  }
}

void loop() {
  // iterate through pins and turn them on then off
  for (int curPin = 2; curPin < 8; curPin++) {
    digitalWrite(curPin, HIGH); // LED on
    delay(timer);
    digitalWrite(curPin, LOW);  // LED off
  }

  // iterate through the pins in reverse order
  for (int curPin = 7; curPin >= 2; curPin--) {
    digitalWrite(curPin, HIGH); // LED on
    delay(timer);
    digitalWrite(curPin, LOW);  // LED off
  }
}
