/*
 * BarGraph
 * 
 * Control the amount of LEDs that are lit up by a pentiometer
 * 
 * Jim Palomo
 */

const int analogPin = A0; // pentiometer pin
const int ledCount = 10;  // # of LEDs

int ledPins[] = {2,3,4,5,6,7,8,9,10,11};  // array of LED pins used

void setup() {
  // initialize LED pins by iterating and set each pin as output
  for (int curLed = 0; curLed < ledCount; curLed++) {
    pinMode(ledPins[curLed], OUTPUT);
  }
}

void loop() {
  // read potentiometer data
  int sensorReading = analogRead(analogPin);

  // map data from [0, # LEDs]
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  for (int curLed = 0; curLed < ledCount; curLed++) {

    // if element in the array at the given index is less than
    // ledLevel, then turn the pin on
    if (curLed < ledLevel) {
      digitalWrite(ledPins[curLed], HIGH);
    }

    else {  // turn off pins that are higher than the ledLevel
      digitalWrite(ledPins[curLed], LOW);
    }
  }
}
