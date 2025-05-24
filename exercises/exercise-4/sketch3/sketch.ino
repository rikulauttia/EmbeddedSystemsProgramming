#define G1 2
#define Y1 3
#define R1 4

#define G2 5
#define Y2 6
#define R2 7

#define G3 8
#define Y3 9
#define R3 10

enum State {
  LANE1_2_RED,
  LANE1_2_YELLOW_TO_GREEN,
  LANE1_2_GREEN,
  LANE1_2_YELLOW_TO_RED,
  LANE3_RED,
  LANE3_YELLOW_TO_GREEN,
  LANE3_GREEN,
  LANE3_YELLOW_TO_RED
};

State currentState = LANE1_2_RED;

enum LightState { RED, YELLOW, GREEN };

void setup() {
  pinMode(G1, OUTPUT); pinMode(Y1, OUTPUT); pinMode(R1, OUTPUT);
  pinMode(G2, OUTPUT); pinMode(Y2, OUTPUT); pinMode(R2, OUTPUT);
  pinMode(G3, OUTPUT); pinMode(Y3, OUTPUT); pinMode(R3, OUTPUT);

  allRed();
}

void loop() {
  switch (currentState) {
    case LANE1_2_RED:
      allRed();
      delay(5000);
      currentState = LANE1_2_YELLOW_TO_GREEN;
      break;

    case LANE1_2_YELLOW_TO_GREEN:
      setLane12(YELLOW);
      delay(1000);
      currentState = LANE1_2_GREEN;
      break;

    case LANE1_2_GREEN:
      setLane12(GREEN);
      delay(5000);
      currentState = LANE1_2_YELLOW_TO_RED;
      break;

    case LANE1_2_YELLOW_TO_RED:
      setLane12(YELLOW);
      delay(1000);
      currentState = LANE3_RED;
      break;

    case LANE3_RED:
      setLane3(RED);
      delay(5000);
      currentState = LANE3_YELLOW_TO_GREEN;
      break;

    case LANE3_YELLOW_TO_GREEN:
      setLane3(YELLOW);
      delay(1000);
      currentState = LANE3_GREEN;
      break;

    case LANE3_GREEN:
      setLane3(GREEN);
      delay(5000);
      currentState = LANE3_YELLOW_TO_RED;
      break;

    case LANE3_YELLOW_TO_RED:
      setLane3(YELLOW);
      delay(1000);
      currentState = LANE1_2_RED;
      break;
  }
}


void setLane12(LightState state) {
  digitalWrite(G1, state == GREEN);
  digitalWrite(Y1, state == YELLOW);
  digitalWrite(R1, state == RED);

  digitalWrite(G2, state == GREEN);
  digitalWrite(Y2, state == YELLOW);
  digitalWrite(R2, state == RED);

  digitalWrite(G3, LOW);
  digitalWrite(Y3, LOW);
  digitalWrite(R3, HIGH);
}

void setLane3(LightState state) {
  digitalWrite(G1, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(R1, HIGH);

  digitalWrite(G2, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(R2, HIGH);

  digitalWrite(G3, state == GREEN);
  digitalWrite(Y3, state == YELLOW);
  digitalWrite(R3, state == RED);
}

void allRed() {
  digitalWrite(G1, LOW); digitalWrite(Y1, LOW); digitalWrite(R1, HIGH);
  digitalWrite(G2, LOW); digitalWrite(Y2, LOW); digitalWrite(R2, HIGH);
  digitalWrite(G3, LOW); digitalWrite(Y3, LOW); digitalWrite(R3, HIGH);
}