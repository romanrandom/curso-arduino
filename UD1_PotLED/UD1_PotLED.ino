void setup() {
  
  // Esto sólo se ejecutará una vez
  pinMode( LED_BUILTIN, OUTPUT ); // En el Arduino UNO, poner LED_BUILTIN equivale a poner 13

}

void loop() {
  
  // Todo lo que esté dentro de loop se repetirá indefinidamente
  
  int retardo = analogRead( A0 ); // La A no es necesaria

  digitalWrite(LED_BUILTIN, HIGH);   // enciende el LED (5v)
  delay(retardo);                    // espera
  
  digitalWrite(LED_BUILTIN, LOW);    // apaga el LED (0v)
  delay(retardo);                    // espera

  // y vuelta al principio de loop()
}
