#define G1 2
#define Y1 3
#define R1 4

#define G2 5
#define Y2 6
#define R2 7

enum State { RED, YELLOW_TO_GREEN, GREEN, YELLOW_TO_RED };
State currentState = RED;

unsigned long previousMillis = 0;
unsigned long stay_time = 0;

void setup() {
  pinMode(G1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(R2, OUTPUT);
  setState(RED);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= stay_time) {
    previousMillis = currentMillis;
    switch (currentState) {
      case RED:
        setState(YELLOW_TO_GREEN);
        break;
      case YELLOW_TO_GREEN:
        setState(GREEN);
        break;
      case GREEN:
        setState(YELLOW_TO_RED);
        break;
      case YELLOW_TO_RED:
        setState(RED);
        break;
    }
  }
}

void setState(State state) {
  currentState = state;
  switch (state) {
    case RED:
      digitalWrite(R1, HIGH);
      digitalWrite(R2, HIGH);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      stay_time = 5000;
      break;

    case YELLOW_TO_GREEN:
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      stay_time = 1000;
      break;

    case GREEN:
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      stay_time = 5000;
      break;

    case YELLOW_TO_RED:
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      stay_time = 1000;
      break;
  }
}
