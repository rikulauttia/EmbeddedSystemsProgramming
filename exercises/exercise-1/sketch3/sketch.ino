const int led1 = 12;
const int led2 = 13;
const int button1 = 6;
const int button2 = 7;

int led1State = LOW;
int led2State = LOW;

int lastButton1State = LOW;
int lastButton2State = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  int buttonstate1 = digitalRead(button1);
  int buttonstate2 = digitalRead(button2);

  if (buttonstate1 == HIGH && lastButton1State == LOW) {
    if (led1State == LOW) {
      led1State = HIGH;
    } else {
      led1State = LOW;
    }
    digitalWrite(led1, led1State);
    delay(200);
  }

  if (buttonstate2 == HIGH && lastButton2State == LOW) {
    if (led2State == LOW) {
      led2State = HIGH;
    } else {
      led2State = LOW;
    }
    digitalWrite(led2, led2State);
    delay(200);
  }

  lastButton1State = buttonstate1;
  lastButton2State = buttonstate2;
}
