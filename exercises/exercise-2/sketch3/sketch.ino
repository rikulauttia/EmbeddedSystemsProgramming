#include <LiquidCrystal_I2C.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_MPU6050 mpu;

const int redLED   = 9;
const int greenLED = 10;
const int blueLED  = 11;

const float tiltThresh  = 4.0; // If X or Y axis shows more than 4 m/s²
const float shakeThresh = 20.0; // If total acceleration is over 2 g (2 × 9.8)

void setup() {
  pinMode(redLED,   OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED,  OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Exercise 2 - Sketch 3");
  if (!mpu.begin()) {
    lcd.clear();
    lcd.print("MPU error!");
    while (1);
  }
  delay(1000);
  lcd.clear();
}

void loop() {
  sensors_event_t a, g, temp; // a=Data from the accelerometer, g=Data from the gyroscope, temp=Data from the temperature sensor 
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x; // movement left/right
  float ay = a.acceleration.y; // movement forward/back


  digitalWrite(redLED,   LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED,  LOW);

  String tiltMsg = "Flat";

  if (ay >  tiltThresh) {
    digitalWrite(greenLED, HIGH);
    tiltMsg = "Forward";
  }
  else if (ay < -tiltThresh) {
    digitalWrite(redLED, HIGH);
    tiltMsg = "Back";
  }
  else if (ax >  tiltThresh) {
    digitalWrite(blueLED, HIGH);
    tiltMsg = "Right";
  }
  else if (ax < -tiltThresh) {
    digitalWrite(blueLED, HIGH);
    tiltMsg = "Left";
  }


  float totalAccel = sqrt(ax*ax + ay*ay + a.acceleration.z * a.acceleration.z); //calculate the total motion in 3D space using the X, Y, and Z values

  if (totalAccel > shakeThresh) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(redLED,   HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED,  HIGH);
      delay(100);
      digitalWrite(redLED,   LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED,  LOW);
      delay(100);
    }
    lcd.clear();
    lcd.print("Shake Detected!");
    delay(700);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ax:");
  lcd.print((int)ax);
  lcd.print(" Ay:");
  lcd.print((int)ay);

  lcd.setCursor(0, 1);
  lcd.print("Tilt: ");
  lcd.print(tiltMsg);
  delay(250);
}