const float BETA = 3950;

const int redLed = 13;
const int yellowLed = 12;
const int blueLed = 11;

void setup() {
  pinMode(A0, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);

  float temperature = 1.0 / (log(1 / (1023.0 / analogValue - 1)) / BETA + (1.0 / 298.15)) - 273.15;

  Serial.println(temperature);

  
  if (temperature < 17.0) {
    digitalWrite(blueLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } 
  else if (temperature >= 18.0 && temperature <= 25.0) {
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  } 
  else if (temperature > 25.0) {
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
  }

  delay(1000);
}