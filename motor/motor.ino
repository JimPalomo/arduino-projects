/*
 * Motor
 * 
 * Motor functionalities
 * 
 * Jim Palomo
 */

const int motorPin = 9; // connected to transistor (base)

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);         // 9600 baud rate serial
}

void loop() {
  int interval = 3000; // 3 sec

  analogWrite(motorPin, 255);   // set motor speed to 255 (max)
  
  delay(interval);
  
  analogWrite(motorPin, 0);     // set motor speed to 0 (min / stop)
  
  delay(interval);

  // Other functions
  //speedUpAndDown();
  serialSpeed();
}

// speedUpAndDown: allow the motor to increase from 0 to 255 and back down to 0.
void speedUpAndDown() {
  int delayInt = 20; // delay interval

  // increase the speed (i) by 1 each iteration
  for (int i = 0; i <= 255; i++) {
    analogWrite(motorPin, i);
    delay(delayInt);
  }

  // decreaase the speed (i) by 1 each iteration
  for (int i = 255; i >= 0; i--) {
    analogWrite(motorPin, i);
    delay(delayInt);
  }
}

void serialSpeed() {
  int speed = 0;

  Serial.println("Enter speed [0,255] & press send");

  while(true) {
    
    // run motor if data was inputted
    while(Serial.available() > 0) {
      speed = Serial.parseInt();        // read in value (int) from serial
      speed = constrain(speed, 0, 255); // make sure input is [0,255]

      Serial.print("Speed: ");
      Serial.println(speed);

      analogWrite(motorPin, speed);     // update speed w/ user input
    
    }
  }
}
