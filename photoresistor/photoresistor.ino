/*
 * Photoresistor
 * 
 * Determine the LED brightness based on the photosensor.
 * 
 * Jim Palomo
 */

const int sensorPin = 0;
const int ledPin = 9;

int lightLevel;
int calibratedLightLevel; // store calibrated light level
int maxThreshold = 0;     // store max light level
int minThreshold = 1023;  // store min light level

void setup() {
  pinMode(ledPin, OUTPUT);  // LED Pin (9) as output
  Serial.begin(9600);
}

void loop() {
  lightLevel = analogRead(sensorPin); // read provided voltage on pin 0
  Serial.print(lightLevel);
  //autoRange();  // check max/min values for light level

  // light level from 0-1023 to 0-255 range
  calibratedLightLevel = map(lightLevel, maxThreshold, 
                              minThreshold, 0, 255);

  Serial.print("\t");
  Serial.print(calibratedLightLevel); // print out calibrated light value

  analogWrite(ledPin, calibratedLightLevel);  // set led level to value of lightlevel input
}

// autoRange: used to calibrate light levels
void autoRange() {
  if (lightLevel < minThreshold)  // update minThreshold
    minThreshold = lightLevel;

  if (lightLevel > maxThreshold)  // update maxThreshold
    maxThreshold = lightLevel;

  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
   
}
