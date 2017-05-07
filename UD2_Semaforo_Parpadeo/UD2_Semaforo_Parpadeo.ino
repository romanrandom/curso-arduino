/**
 * Unidad 2: Semáforo (Con luz ámbar parpadeante)
 * 
 * En esta variante usamos un cronómetro para parpadear el LED ámbar 
 * usando la técnica de este ejemplo:
 * http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 * 
 * El parpadeo sólo se producirá mientras estemos en el modo ámbar
 */

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
unsigned long milisActuales;             // Variable para guardar el tiempo actual (en ms)
unsigned long milisParpadeoAnterior = 0; // Última vez que el LED ámbar cambió
const int intervaloParpadeo = 500;       // También en ms

void setup() {
  // Inicializamos los pin de los LED
  pinMode(ledRojoPin, OUTPUT);
  pinMode(ledAmbarPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  // Inicializamos el botón como entrada a 5v en reposo activando la resistencia pull-up interna
  pinMode(botonPin, INPUT_PULLUP);
}

void loop() {
  
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
          // En este caso reseteamos las variables usadas para el parpadeo
          // así empieza siempre encendido
          milisParpadeoAnterior = millis();
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

  // Sólo hacemos los cálculos si estamos en el estado correspondiente
  if (estadoSemaforo == 1) {
  
    milisActuales = millis();
  
    if (milisActuales - milisParpadeoAnterior >= intervaloParpadeo) {
      
      milisParpadeoAnterior = milisActuales;
      estadoAmbar = !estadoAmbar; // Niega lo que haya en estadoAmbar
                                  // si era HIGH (o true, o 1) se vuelve LOW (o false, o 0)
                                  // si era LOW se vuelve HIGH
    }
  
    // Para que el LED parpadee, debe cambiar la salida del pin fuera del condicional
    // que controla si se ha pulsado un botón
  
    digitalWrite(ledAmbarPin, estadoAmbar);
  }
  
}
