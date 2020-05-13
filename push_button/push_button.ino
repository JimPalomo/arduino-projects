/*
 * Push buttons
 * 
 * Aloow the LED to blink by pushing a button
 * 
 * Jim Palomo
 */

// set values of pins
const int pushButtonPin = 2;  // pin 2 --> push button
const int ledPin = 13;        // pin 13--> LED

int buttonState = 0;          // set state of button to 0 (not pushed)

void setup() {
    pinMode(pushButtonPin, INPUT);  // set pushButtonPin as input 
    pinMode(ledPin, OUTPUT);        // set ledPin to output
}

void loop() {
  // reads the current state of the push button from the input
  buttonState = digitalRead(pushButtonPin);

  // check to see if push button is being pressed
  if (buttonState == HIGH) {  // button is pressed
    digitalWrite(ledPin, HIGH); // set LED to high
  }

  else {  // button is not pressed
    digitalWrite(ledPin, LOW);  // set LED to low
  }
}
