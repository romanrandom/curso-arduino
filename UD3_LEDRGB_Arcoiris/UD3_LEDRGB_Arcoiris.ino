/**
 * Unidad 3: LED RGB Arco Iris
 * 
 * Recorremos todo el espectro de colores reproducible con 24bits
 */

byte pinRGB[] = {9, 10, 11};


void setup() {
  
  for (byte i = 0; i < 3; i++) {
    pinMode(pinRGB[i], OUTPUT);  
  }
  //Serial.begin(9600);
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
  
  byte c[3];
  
  for (int r = 0; r < 256; r+=10) {
    for (int g = 100; g < 256; g+=5) {
      for (int b = 0; b < 256; b++) {
        
        byte c[] = {r,g,b};
     
        color(c);
        /*
        Serial.print(r);
        Serial.print(',');
        Serial.print(g);
        Serial.print(',');
        Serial.println(b);
        */
      }
    }
  }
  

}
