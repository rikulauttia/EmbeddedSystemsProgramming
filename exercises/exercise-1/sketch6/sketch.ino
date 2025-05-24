int brightnessLevels[] = {0, 20, 100, 255};
int currentLevel = 3;
int lastButtonState = LOW;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(7, INPUT);
  analogWrite(9, brightnessLevels[currentLevel]);
}

void loop() {
  int buttonState = digitalRead(7);

  if (buttonState == HIGH && lastButtonState == LOW) {
    currentLevel = currentLevel - 1;

    if (currentLevel < 0) {
      currentLevel = 3;
    }

    analogWrite(9, brightnessLevels[currentLevel]);
    delay(200);
  }

  lastButtonState = buttonState;
}