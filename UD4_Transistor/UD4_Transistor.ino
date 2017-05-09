/**
 * Unidad 4: Transistor controlando un motor DC
 * 
 * Mediante el uso de un transistor vamos aumentando 
 * la velocidad de un motor DC
 */

const byte pinMotor = 9;

void setup() {    
  pinMode(pinMotor, OUTPUT);
}

void loop() { 
  
  for (int v = 0; v < 255; v++) {
    analogWrite(pinMotor, v);
    delay(20);
  }
  analogWrite(pinMotor, 0); // Lo paramos y esperamos a que deje de girar
  delay(2000);
}
