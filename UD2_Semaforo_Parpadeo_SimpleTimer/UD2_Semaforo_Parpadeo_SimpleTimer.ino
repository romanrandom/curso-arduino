/**
 * Unidad 2: Semáforo (Con luz ámbar parpadeante y SimpleTimer)
 * 
 * En esta variación del ejercicio usaremos una librería
 * para parpadear el LED ámbar más cómodamente:
 * http://playground.arduino.cc/Code/SimpleTimer
 * Para instalarla hay que seguir las instrucciones de su autor,
 * ya que no se encuentra disponible en el gestor de librerías.
 * Esta instalación manual consiste en crear dos archivos,
 * SimpleTimer.h y SimpleTimer.cpp
 * copiar el código correspondiente en ellos,
 * copiar los archivos a la carpeta de librerías sketchbook/libraries/SimpleTimer
 * y reiniciar Arduino
 */

#include <SimpleTimer.h>

// constantes, no cambian
const int botonPin = 2;
const int ledRojoPin =  13;
const int ledAmbarPin =  12;
const int ledVerdePin =  11;

// variables, cambian
int estadoSemaforo = 0;       // 0-verde 1-ámbar 2-rojo
int estadoBoton = 0;          // estado actual del botón
int ultimoEstadoBoton = HIGH;

// Usamos unsigned long ya que el tiempo en milisegundos crece muy rápido y sale del rango de los int
unsigned long lastDebounceTime = 0;  // la última vez que algún pin de salida se activó
unsigned long debounceDelay = 50;    // tiempo de debounce; aumentar si la salida parpadea


/*** Parpadeo de la luz ámbar ***/

bool estadoAmbar = HIGH;                 // Variable global que indica el estado del LED ámbar
SimpleTimer timer;
byte timerParpadeoID;

void setup() {
  
  // Inicializamos los pin de los LED
  pinMode(ledRojoPin, OUTPUT);
  pinMode(ledAmbarPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  // Inicializamos el botón como entrada a 5v en reposo activando la resistencia pull-up interna
  pinMode(botonPin, INPUT_PULLUP);

  timerParpadeoID = timer.setInterval(500, cambiaEstadoAmbar);  // Inicializamos el timer con el 
                                                                // tiempo de intervalo y la función (callback)
                                                                // que se debe ejecutar cada intervalo
}

void cambiaEstadoAmbar() {
  estadoAmbar = !estadoAmbar;
}

void loop() {

  timer.run();
  
  // Leemos el estado del pin del botón y lo guardamos en una variable local
  int leyendo = digitalRead(botonPin);

  // Comprobamos si se acaba de pulsar el botón (HIGH -> LOW) y si hemos esperado suficiente tiempo
  // desde la últia pulsación para ignorar cualquier ruido.

  // Si ha cambiado, a causa de ruido o pulsación voluntaria
  if (leyendo != ultimoEstadoBoton) {
    // reiniciamos el temporizador de debounce
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
 
    // El pin del botón lleva leyendo el mismo valor durante más tiempo que el retraso de debounce,
    // así que asumimos que es el estado actual

    // Si el esado ha cambiado
    if (leyendo != estadoBoton) {
      estadoBoton = leyendo;
      
      // Cambiamos el estado del semáforo si se ha pulsado el botón
      if (estadoBoton == LOW) {
        // Usamos el resto de la división entre 3 para que se mantenga entre 0 y 2
        estadoSemaforo = (estadoSemaforo + 1) % 3;
      }
  
      // Apagamos todos los LEDs
      digitalWrite(ledRojoPin, LOW);
      digitalWrite(ledAmbarPin, LOW);
      digitalWrite(ledVerdePin, LOW);
  
      // Y encendemos sólo al que le toca
      switch (estadoSemaforo) {
        
        case 0:
          digitalWrite(ledVerdePin, HIGH);
          break;
          
        case 1:
          // Reiniciamos el timer del parpadeo
          // para que empiece encendido la próxima vez
          timer.restartTimer(timerParpadeoID);
          estadoAmbar = HIGH;
          break;
        
        case 2:
          digitalWrite(ledRojoPin, HIGH);
          break;
      }
    }
  }

  // Guardamos el estado para comparar con la lectura de la siguiente vuelta del bucle
  ultimoEstadoBoton = leyendo;


  /*** Parpadeo LED Ámbar ***/
  if (estadoSemaforo == 1) {
  
    digitalWrite(ledAmbarPin, estadoAmbar);
  }
  
}
