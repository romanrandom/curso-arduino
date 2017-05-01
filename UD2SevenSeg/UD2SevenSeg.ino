#include <SevenSeg.h>

// Configuramos los pines a los que están conectados los segmentos
// ABCDEFG
SevenSeg disp(2,3,4,5,6,7,8);

void setup() {
  
  disp.setDPPin(9); // Punto decimal
  disp.setCommonCathode();
}  

void loop() {

  disp.writeDigit(2);
  disp.setDP(); // Enciende el punto
}
