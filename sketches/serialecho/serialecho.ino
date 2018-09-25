byte b;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    b = Serial.read();
    Serial.write(b);
  }
}
