/**  
 *   Unidad 5: Mozzi
 *   
 *   Reproduciendo todo el espectro audible desde 20 hasta 20000Hz
 *   Usamos una onda sinusoidal
 *   Usa Oscil para reproducir un wavetable
 *   La salida de audio está en el pin 9
*/

#include <MozziGuts.h>
#include <Oscil.h>                // plantilla de oscilador
#include <tables/sin2048_int8.h>  // tabla de seno para el oscilador

// Uso: Oscil <tamaño_tabla, velocidad_refresco> nombreOscilador (wavetable), mirar en archivo .h de la tabla #incluida arriba
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// Cuántas veces por segundo se ejecuta la función updateControl()
// Hay que usar #define para CONTROL_RATE, no una constante
#define CONTROL_RATE 64 // potencias de 2 desde 64 hasta 1024

float frec = 20;
int volumen = 1;

void setup() {
  
  startMozzi(CONTROL_RATE);
  Serial.begin(115200);
  
}


void updateControl() {

  frec+=frec*0.005;
  Serial.println(frec);
  aSin.setFreq(frec);
  
  if (frec > 20000) {
    volumen = 0;
  }
}


int updateAudio() {
  
  return aSin.next() * volumen; // Devuelve una señal int centrada alrededor de 0
  
}


void loop(){
 
  audioHook();          // requerido
  
}



