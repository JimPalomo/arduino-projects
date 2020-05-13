/*
 * Fading LED
 * 
 * Control LED brightness
 * 
 * Jim Palomo
 */

int ledPWM = 9;     // PWM pin for LED (Pulse Width Modulation)
int brightness = 0; // LED brightness
int fadeAmount = 5; // Dim the LED (will increment by 5 each time)

void setup() {
  pinMode(ledPWM, OUTPUT);  // led pin (9) as output
}

void loop() {
  // set brightness of PWM LED pin
  analogWrite(ledPWM, brightness);

  // set the brightness value for the next loop iteration 
  brightness += fadeAmount;  

  // allow the fade to fade in the opposite direction
  // done by reversing the fade to create a pulse effect
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);  // 30 ms delay
}
