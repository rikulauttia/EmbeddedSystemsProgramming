int ledState = LOW;
int buttonState = LOW;
int previousButtonState = LOW;

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  buttonState = digitalRead(2);

  if (buttonState == HIGH && previousButtonState == LOW) {
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(13, ledState);
    delay(200);
  }

  previousButtonState = buttonState;
}
