/**
 * Unidad 4: Relé
 * 
 * Ejemplo del funcionamiento de un relé conectando
 * un LED a NC (Normally closed) y otro a NO (Normally Open)
 */

const byte pinRele = 9;

void setup() {    
  pinMode(pinRele, OUTPUT);
}

void loop() { 
  
  digitalWrite(pinRele, HIGH);
  delay(1000);
  
  analogWrite(pinRele, LOW); 
  delay(1000);
}
