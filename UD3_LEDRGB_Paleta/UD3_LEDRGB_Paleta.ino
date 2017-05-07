/**
 * Unidad 3: LED RGB Paleta
 * 
 * Definimos una paleta de colores con la que trabajar
 */

byte pinRGB[] = {9, 10, 11};

byte paleta[][4] = {
  {255, 0,   0  },
  {0,   50,  100},
  {255, 0,   255},
  {255, 255, 255}
};

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

  color(paleta[random(4)]);
  delay(random(1000));
}
