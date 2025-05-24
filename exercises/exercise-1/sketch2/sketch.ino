const int led1 = 12;
const int led2 = 13;
const int buttonPin = 2;

int pressingCount = 0;
int lastButtonState = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount = pressCount + 1;

    if (pressingCount == 1) {
      digitalWrite(led1, HIGH);
    } else if (pressingCount == 2) {
      digitalWrite(led2, HIGH);
    } else if (pressingCount == 3) {
      digitalWrite(led2, LOW);
    } else if (pressingCount == 4) {
      digitalWrite(led1, LOW);
      pressingCount = 0;
    }
    
  }

  lastButtonState = buttonState;
}