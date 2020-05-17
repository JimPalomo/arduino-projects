/*
 * Servo
 * 
 * Testing a servomotor
 * 
 * Jim Palomo
 */
 
#include <Servo.h>

Servo servo;  // instance of servo (created object)

void setup() {
  // servo connected to pin 9 w/ 900-2100 pwm
  servo.attach(9, 900, 2100);
}

void loop() {
  // servo can go from 0 - 180 degrees
  int wait = 1000;  // 1 sec delay

//  servo.write(0);  // servo pos 90 degrees
//
//  delay(wait);
//
//  servo.write(90);
//
//  delay(wait);
//
//  servo.write(180);
//
//  delay(wait);

  // rotate from 0 to 180 degrees
  for (int i = 0; i < 180; i += 5) {
    servo.write(i);
    delay(20);
  }

  // rotate from 180 to 0 degrees
  for (int i = 180; i >= 0; i -= 5) {
    servo.write(i);
    delay(20);
  }

}
