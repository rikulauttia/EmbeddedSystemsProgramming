const int ledPin = 9;
const int buttonDown = 6;
const int buttonUp = 7;

int brightnessLevels[] = {0, 36, 72, 108, 144, 180, 216, 255}; // all the brigthness levels
int currentLevel = 7;// starting with full brigyhness
int lastButtonDownState = LOW;
int lastButtonUpState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonUp, INPUT);
  analogWrite(ledPin, brightnessLevels[currentLevel]);
}

void loop() {
  int buttonDownState = digitalRead(buttonDown);
  int buttonUpState = digitalRead(buttonUp);

  // Decrease brightness
  if (buttonDownState == HIGH && lastButtonDownState == LOW) {
    currentLevel = currentLevel - 1;
    if (currentLevel < 0) {
      currentLevel = 7; // Go back to max brightness
    }
    analogWrite(ledPin, brightnessLevels[currentLevel]);
    delay(200); // Simple debounce
  }

  // Increase brightness
  if (buttonUpState == HIGH && lastButtonUpState == LOW) {
    currentLevel = currentLevel + 1;
    if (currentLevel > 7) {
      currentLevel = 0; // Go back to OFF
    }
    analogWrite(ledPin, brightnessLevels[currentLevel]);
    delay(200); // Simple debounce
  }

  lastButtonDownState = buttonDownState;
  lastButtonUpState = buttonUpState;
}
