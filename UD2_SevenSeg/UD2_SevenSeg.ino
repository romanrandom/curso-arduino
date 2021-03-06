/**
 * Unidad 2: SevenSeg
 * 
 * Usando la librería SevenSeg instalada a través del gestor,
 * mostraremos un dígito o letra en un display de 7 segmentos
 * https://github.com/sigvaldm/SevenSeg/blob/master/extras/SevenSeg.pdf
 */
 
#include <SevenSeg.h>

// Configuramos los pines a los que están conectados los segmentos
// en el siguiente orden; ABCDEFG
SevenSeg disp(2,3,4,5,6,7,8);

void setup() {
  
  disp.setDPPin(9);         // Definimos el pin al que está conectado el punto decimal
  disp.setCommonCathode();  // Configuramos el modo en que funciona el display
                            // en caso de ser de ánodo común esta línea no haría falta
}  

void loop() {

  disp.writeDigit('R');   // La librería acepta números del 0 al 9 y letras (ver manual para más)
                          // Las letras deben ir entre comillas
  disp.setDP();           // Enciende el punto decimal
  
}
