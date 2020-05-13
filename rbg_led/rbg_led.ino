/*
 * RGB LED
 * 
 * RGB LED functions (main colors & spectrum)
 * 
 * Jim Palomo
 */

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

const int DISPLAY_TIME = 1000;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
//  displayMain();      // display the main colors
  displaySpectrum();  // display spectrum of colors by fading
}

void displayMain() {
  
  // all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(DISPLAY_TIME);

  // Red
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(DISPLAY_TIME);

  // Green
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(DISPLAY_TIME);

  // Blue
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DISPLAY_TIME);

  // Yellow 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(DISPLAY_TIME);

  // Cyan 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DISPLAY_TIME);

  // Purple 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DISPLAY_TIME);

  // White 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DISPLAY_TIME);  
}

// displaySpectrum: show spectrum of colors
void displaySpectrum() {
  for (int i = 0; i <= 767; i++) {
    RGB(i);      // set RGB value
    delay(10);   // debouncing
  }
}


/*
 * RGB: display color given the RGB content
 * 
 * The "base" numbers are:
 * 0   = pure red
 * 255 = pure green
 * 511 = pure blue
 * 767 = pure red (again)
 * 
 * From makespace
 */
void RGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  color = constrain(color, 0, 767); // constrain the input value to a range of values from 0 to 767

    // if statement breaks down the "color" into three ranges:
  if (color <= 255)       // RANGE 1 (0 - 255) - red to green
  {
    redIntensity = 255 - color;    // red goes from on to off
    greenIntensity = color;        // green goes from off to on
    blueIntensity = 0;             // blue is always off
  }
  else if (color <= 511)  // RANGE 2 (256 - 511) - green to blue
  {
    redIntensity = 0;                     // red is always off
    greenIntensity = 511 - color;         // green on to off
    blueIntensity = color - 256;          // blue off to on
  }
  else                    // RANGE 3 ( >= 512)- blue to red
  {
    redIntensity = color - 512;         // red off to on
    greenIntensity = 0;                 // green is always off
    blueIntensity = 767 - color;        // blue on to off
  }

  // "send" intensity values to the Red, Green, Blue Pins using analogWrite()
  analogWrite(RED_PIN, redIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
}
