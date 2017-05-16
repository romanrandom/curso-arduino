void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.write(analogRead(0) / 4);
  Serial.println(analogRead(0));
  delay(40);
}
