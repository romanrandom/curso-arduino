/**
 * Unidad 3: LightBuzzer con ajuste de mínimo y máximo
 * 
 * Hacemos sonar un altavoz piezoeléctrico (buzzer)
 * con un LDR (Light Dependant Resistor) usando
 * un la configuración de un divisor de tensión.
 */

const byte pinBuzzer = 10;
const byte pinBoton  = 2;

// Definimos las variables que albergarán los valores más extremos obtenidos
// desde el comienzo del programa
int minim = 1023;
int maxim = 0;
 
void setup() {
  
  pinMode(pinBuzzer, OUTPUT); 
  pinMode(pinBoton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int luz = analogRead(A0);

  // Actualizamos mínimo y máximo
  if (luz < minim) minim = luz;
  if (luz > maxim) maxim = luz;

  Serial.print("Min: ");
  Serial.print(minim);
  Serial.print(" Max: ");
  Serial.print(maxim);
  Serial.print("  ");
  Serial.println(luz);
  
  // Mapeamos los valores obtenidos del sensor a frecuencias
  // que el buzzer pueda reproducir (esta vez invertidos
  // para que suba la frecuencia con la luz)
  int frec = map(luz, minim, maxim, 5000, 1000);
  
  // Hacemos sonar el buzzer a la frecuencia calculada usando PWM
  // cuando esté pulsado el botón
  if (digitalRead(pinBoton) == LOW) {
    
    tone(pinBuzzer, frec);
    
  // Dejamos de emitir cuando soltamos el botón
  } else {
    
    noTone(pinBuzzer);
    
  }
}
