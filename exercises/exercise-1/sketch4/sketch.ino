const float BETA = 3950;

void setup() {
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);
  float temperature = 1.0 / (log(1/ (1023. / analogValue - 1)) / BETA + (1.0 / 298.15)) - 273.15;
  Serial.println(temperature);

  if (temperature > 30.0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  delay(1000);
}