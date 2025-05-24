const int led1 = 4;
const int led2 = 5;

volatile bool led1State = false;
volatile bool led2State = false;

void toggleLed1() {
  led1State = !led1State;
  digitalWrite(led1, led1State);
}

void toggleLed2() {
  led2State = !led2State;
  digitalWrite(led2, led2State);
}

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), toggleLed1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), toggleLed2, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}