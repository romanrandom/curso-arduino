/**
 * Unidad 2: SevenSeg con cuenta atrás
 * 
 * Usando la librería SevenSeg y SimpleTimer,
 * crearemos una cuenta atrás
 * en un display de 7 segmentos
 */
 
#include <SevenSeg.h>
#include <SimpleTimer.h>

// Configuramos los pines a los que están conectados los segmentos
// en el siguiente orden; ABCDEFG
SevenSeg disp(2,3,4,5,6,7,8);

SimpleTimer timer;
byte contador = 9;

void setup() {
  
  disp.setDPPin(9);         // Definimos el pin al que está conectado el punto decimal
  disp.setCommonCathode();  // Configuramos el modo en que funciona el display
                            // en caso de ser de ánodo común esta línea no haría falta

  timer.setInterval(500, cuentaAtras);
}  

void cuentaAtras() {

  if (contador > 0) {
    contador--; // Restamos 1 a contador mientras sea mayor que 0
  }
}

void loop() {

  timer.run();

  disp.writeDigit(contador);   // La librería acepta números del 0 al 9 y letras (ver manual para más)
                          // Las letras deben ir entre comillas
  disp.setDP();           // Enciende el punto decimal
  
}
