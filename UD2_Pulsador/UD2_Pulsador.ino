const byte pin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println( digitalRead(pin) );
}
