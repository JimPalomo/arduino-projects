/*
 * LCD Screen
 * 
 * Test out LCD Screen w/ LiquidCrystal library
 * 
 * Jim Palomo
 */

#include <LiquidCrystal.h>

// Create LCD object & initialize pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2); // initialize 16x2 LCD

  lcd.clear();      // clear previous LCD data

  lcd.print("Hello World!");  // display on LCD

  lcd.setCursor(0,1);

  lcd.print("This is a test");
}

void loop() {
  lcd.setCursor(13,0);  // set cursor to (col, row)

  lcd.print(millis() / 1000); // print each second 
}
