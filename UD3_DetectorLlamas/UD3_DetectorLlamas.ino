void setup() {
  pinMode(9, OUTPUT);
}
int v;
void loop() {
  v = analogRead(A0) ;
  if ( v > 20) pita(500);
}
  
void pita(unsigned int pausa) {
  /*analogWrite(9, v/4);
  delay(pausa);
  analogWrite(9, 0);
  delay(pausa);
  */
  tone(9,v*4,pausa);
}
