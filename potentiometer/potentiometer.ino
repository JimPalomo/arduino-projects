/*
 * Potentiometer (LED duration)
 * 
 * Control the LED duration with a potentiometer
 * 
 * Jim Palomo
 */

int ledPin = 13;      // LED pin
int sensorPin = A0;   // input pin for potentiometer
int sensorValue = 0;  // sensor value recorded from potentiometer

void setup() {
  pinMode(ledPin, OUTPUT);  // LED pin set as output
}

void loop() {
  // read value inputted from potentiometer
  sensorValue = analogRead(sensorPin);  

  digitalWrite(ledPin, HIGH); // set LED pin on
  delay(sensorValue);         // delay w/ potentiometer value
  
  digitalWrite(ledPin, LOW);  // set LED pin off
  delay(sensorValue);
}
