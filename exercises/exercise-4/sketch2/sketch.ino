#define G1 2
#define G2 3
#define Y1 4
#define Y2 5
#define R1 6
#define R2 7
#define PG1 8
#define PG2 9
#define PR1 10
#define PR2 11
#define B1 12
#define B2 13

enum TrafficState { GREEN, YELLOW, RED };
enum PedestrianState { GREEN_P, RED_P };

bool pedestrianRequest = false;

void setup() {
  pinMode(G1, OUTPUT); pinMode(G2, OUTPUT);
  pinMode(Y1, OUTPUT); pinMode(Y2, OUTPUT);
  pinMode(R1, OUTPUT); pinMode(R2, OUTPUT);

  pinMode(PG1, OUTPUT); pinMode(PG2, OUTPUT);
  pinMode(PR1, OUTPUT); pinMode(PR2, OUTPUT);

  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);

  digitalWrite(PR1, HIGH); digitalWrite(PR2, HIGH);
  digitalWrite(PG1, LOW); digitalWrite(PG2, LOW);
}

void loop() {
  setTraffic(GREEN);
  setPedestrian(RED_P);
  waitWithButtonCheck(5000);

  setTraffic(YELLOW);
  delay(1000);

  setTraffic(RED);
  setPedestrian(GREEN_P);
  delay(5000);

  setPedestrian(RED_P);
  delay(1000);

  setTraffic(YELLOW);
  delay(1000);

  pedestrianRequest = false;
}

void waitWithButtonCheck(unsigned long total) {
  unsigned long start = millis();
  while (millis() - start < total) {
    if (!digitalRead(B1) || !digitalRead(B2)) {
      pedestrianRequest = true;
      break;
    }
  }
}

void setTraffic(TrafficState state) {
  digitalWrite(G1, state == GREEN);
  digitalWrite(G2, state == GREEN);
  digitalWrite(Y1, state == YELLOW);
  digitalWrite(Y2, state == YELLOW);
  digitalWrite(R1, state == RED);
  digitalWrite(R2, state == RED);
}

void setPedestrian(PedestrianState state) {
  digitalWrite(PG1, state == GREEN_P);
  digitalWrite(PG2, state == GREEN_P);
  digitalWrite(PR1, state == RED_P);
  digitalWrite(PR2, state == RED_P);
}