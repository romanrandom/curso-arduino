/**
 * Unidad 3: LightBuzzer o Buzz Lightyear
 * 
 * Hacemos sonar un altavoz piezoeléctrico (buzzer)
 * con un LDR (Light Dependant Resistor) usando
 * la configuración de un divisor de tensión.
 */

const byte pinBuzzer = 10;
const byte pinBoton  = 2;
 
void setup() {
  
  pinMode(pinBuzzer, OUTPUT); 
  pinMode(pinBoton, INPUT_PULLUP);

}

void loop() {

  int luz = analogRead(A0);
  
  // Mapeamos los valores obtenidos del sensor a frecuencias
  // que el buzzer pueda reproducir
  int frec = map(luz, 0, 1023, 1000, 5000);
  
  // Hacemos sonar el buzzer a la frecuencia calculada usando PWM
  // cuando esté pulsado el botón
  if (digitalRead(pinBoton) == LOW) {
    tone(pinBuzzer, frec);
  // Dejamos de emitir cuando soltamos el botón
  } else {
    noTone(pinBuzzer);
  }
  
}
