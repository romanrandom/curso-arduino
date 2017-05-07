/**
 * Unidad 3: LED RGB Random
 * 
 * Esta vez el color cambiará cada cierto tiempo aleatorio 
 * a un valor aleatorio
 */

byte pinRGB[] = {9, 10, 11};

void setup() {
  
  for (byte i = 0; i < 3; i++) {
    pinMode(pinRGB[i], OUTPUT);  
  }
  
}

/**
 * Función que activa los pines correspondientes para mostrar
 * el color que se le pasa en forma de array
 */
void color(byte RGB[]) {
  
  for (byte i = 0; i < 3; i++) {
    analogWrite(pinRGB[i], RGB[i]);  
  }
}

void loop() {

  byte rojo[] = {random(255), random(255), random(255)};
  
  color(rojo);
  
  delay(random(1000));
}
