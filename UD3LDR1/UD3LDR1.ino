const int pinBuzzer = 10;
 
void setup() {
  pinMode(pinBuzzer, OUTPUT); 
}

void loop() {
  int luz = analogRead(A0);
  int frec = map(luz, 0, 1024, 20, 5000);
  tone(pinBuzzer, frec);
}
