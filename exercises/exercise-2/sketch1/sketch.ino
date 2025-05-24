int red   = 9;
int green = 10;
int blue  = 11;

void setup() {
  pinMode(red,   OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue,  OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter LED (R/G/B) and brightness (0-255):");
}

void loop() {
  if (Serial.available()) {
    String in = Serial.readStringUntil('\n');
    in.trim();

    char led = in.charAt(0);
    int val  = in.substring(1).toInt();

    if (val < 0 || val > 255) {
      Serial.println("Invalid input. Use format: for example R150, G225 OR B100");
      return;
    }

    if (led == 'R') {
      analogWrite(red, val);
      Serial.print("Red LED set to ");  Serial.println(val);
    } else if (led == 'G') {
      analogWrite(green, val);
      Serial.print("Green LED set to ");Serial.println(val);
    } else if (led == 'B') {
      analogWrite(blue, val);
      Serial.print("Blue LED set to "); Serial.println(val);
    } else {
      Serial.println("Invalid input. Use format: for example R150, G225 OR B100");
    }

    Serial.println("Enter LED (R/G/B) and brightness (0-255):");
  }
}