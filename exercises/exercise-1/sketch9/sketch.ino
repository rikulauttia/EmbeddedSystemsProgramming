const int tempPin = A0;
const int ledPin = 9;

const float BETA = 3950;
const int brightnessLevels[] = {0, 85, 170, 255};

void setup() {
  pinMode(tempPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(tempPin);

  float temperature = 1.0 / (log(1 / (1023.0 / analogValue - 1)) / BETA + (1.0 / 298.15)) - 273.15;

  Serial.println(temperature);

  int level = 0;

  if (temperature >= 0) {
    level = map(temperature, 0, 20, 0, 3);

    if (level < 0) level = 0;
    if (level > 3) level = 3;
  }

  int brightness = brightnessLevels[level];
  analogWrite(ledPin, brightness);
  delay(500);
}
