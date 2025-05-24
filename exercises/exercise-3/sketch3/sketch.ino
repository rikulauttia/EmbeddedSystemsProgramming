const int sensorPin = A0;
const int ledPin = 4;

volatile bool tempChecked = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  cli();
  PCICR |= (1 << PCIE1);
  PCMSK1 |= (1 << PCINT8);
  sei();
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float temperatureC = 1.0 / (log(1.0 / (1023.0 / sensorValue - 1.0)) / 3950.0 + 1.0 / 298.15) - 273.15;
  
  if (temperatureC > 30.0) {
    PORTC |= (1 << PC0);
  } else {
    PORTC &= ~(1 << PC0);
    digitalWrite(ledPin, LOW);
  }

  tempChecked = true;

  delay(500);
}

ISR(PCINT1_vect) {
  if (tempChecked) {
    if (PINC & (1 << PC0)) {
      digitalWrite(ledPin, HIGH);
    }
    
    tempChecked = false;
  }
}