/*
 * Multiple LED
 * 
 * Apply multiple LED functions
 * 
 * Jim Palomo
 */

int ledPins[] = {2,3,4,5,6,7,8,9};

void setup() {
  // initialize pins 2-9 as output
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // uncomment to select LED function
//  oneAfterAnother();  // light up all LEDs one at a time
  
//  oneOnAtATime();     // have only one LED on at a time
  
  pingPong();         // have leds light up going back & forth
  
//  marquee();          // follow the next sequencial LED
  
//  randomLED();        // randomize LED pattern
}

// oneAfterAnother: light up all LEDs one at a time
void oneAfterAnother() {
  int timer = 100;  // delay

  // turn all LEDs on
  for (int i = 0; i <= 7; i++) {
    digitalWrite(ledPins[i], HIGH); // LED on
    delay(timer);
  }

  // turn all LEDs off
  for (int i = 7; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(timer);
  }
}

// oneOnAtATime: have only one LED on at a time
void oneOnAtATime() {
  int timer = 100;  // delay

  // iterate through all LEDs
  for (int i = 0; i <= 7; i++) {
    digitalWrite(ledPins[i], HIGH); // LED on
    delay(timer);
    digitalWrite(ledPins[i], LOW);  // LED off
  }
}

// pingPong: have leds light up going back & forth
void pingPong()
{
  int timer = 100;  // delay
   
  // turn LEDs on going one way
  for (int i = 0; i <= 7; i++) {
    digitalWrite(ledPins[i], HIGH);  // LED on
    delay(timer);                    
    digitalWrite(ledPins[i], LOW);   // LED off
  }
 
  // turn LEDs on going the reverse order
  for(int i = 7; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);  // LED on
    delay(timer);                    
    digitalWrite(ledPins[i], LOW);   // LED off
  }
}

// marquee: follow the next sequencial LED
void marquee()
{
  int timer = 200;  // delay
 
  // Light up LEDs in marquee order
  for(int i = 0; i <= 3; i++) // Step from 0 to 3
  {
    digitalWrite(ledPins[i], HIGH);    // LED on
    digitalWrite(ledPins[i+4], HIGH);  // Skip four, set LED on
    delay(timer);                   
    digitalWrite(ledPins[i], LOW);     // LED off
    digitalWrite(ledPins[i+4], LOW);   // Skip four, set LED off
  }
}

// randomLED: randomize LED pattern
void randomLED()
{
  int i;
  int timer;
  
  i = random(8);  // random number [0,7]
  timer = 100;
  
  digitalWrite(ledPins[i], HIGH);  // LED on
  delay(timer);                    
  digitalWrite(ledPins[i], LOW);   // LED off
}
