#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const char message[] = "Welcome to the DTEK0074-3006 Embedded System Programming";
volatile bool buttonPressed = false;

void handleButtonPress() {
  buttonPressed = true;
}

void setup() {
  lcd.begin(16, 2);
  lcd.autoscroll();
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), handleButtonPress, FALLING);
}

void loop() {
  if (buttonPressed) {
    if (digitalRead(2) == LOW) {
      lcd.clear();
      lcd.noAutoscroll();
      lcd.setCursor(0, 0);
      lcd.print("Exercise 3");
      delay(100);
    } else {
      buttonPressed = false;
      lcd.clear();
      lcd.autoscroll();
    }
  } else {
    static int i = 0;
    lcd.print(message[i]);
    i = (i + 1) % strlen(message);
    delay(300);
  }
}