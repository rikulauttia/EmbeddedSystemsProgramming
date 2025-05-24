const int tempPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(tempPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  int brightness = map(sensorValue, 1023, 0, 0, 255);

  analogWrite(ledPin, brightness);

  delay(100);
}