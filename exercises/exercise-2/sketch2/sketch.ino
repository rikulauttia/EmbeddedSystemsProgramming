#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,12};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String storedPassword = "";
int attempts = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  showMenu();
}

void loop() {
  char key = keypad.getKey();

  if (key == '1') {
    newUserFlow();
  } else if (key == '2') {
    existingUserFlow();
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. New User");
  lcd.setCursor(0, 1);
  lcd.print("2. Existing User");
  attempts = 0;
}

void newUserFlow() {
  String pass1 = enterPassword("Set Password:");
  String pass2 = enterPassword("Re-enter Pass:");

  if (pass1 == pass2 && pass1.length() == 4) {
    storedPassword = pass1;
    lcd.clear();
    lcd.print("Password Set!");
    delay(2000);
    lcd.clear();
    lcd.print("Enter Password:");
  } else {
    lcd.clear();
    lcd.print("Mismatch. Try again.");
    delay(2000);
    showMenu();
  }
}

void existingUserFlow() {
  String input = enterPassword("Enter Password:");

  if (input == storedPassword) {
    lcd.clear();
    lcd.print("Access Granted!");
    delay(2000);
    showMenu();
  } else {
    attempts++;
    lcd.clear();
    lcd.print("Mismatch. Try again.");
    delay(1500);

    if (attempts >= 3) {
      showMenu();
    } else {
      existingUserFlow();
    }
  }
}

String enterPassword(String prompt) {
  lcd.clear();
  lcd.print(prompt);
  lcd.setCursor(0, 1);
  String password = "";

  while (password.length() < 4) {
    char key = keypad.getKey();
    if (key && key >= '0' && key <= '9') {
      password += key;
      lcd.print("*");
    }
  }

  delay(500);
  return password;
}