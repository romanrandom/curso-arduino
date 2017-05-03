void setup() {
  // Esto sólo se ejecutará una vez
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Todo lo que esté dentro de loop se repetirá indefinidamente
  
  int sensorValue = analogRead(A0);
  delay(1);
  
  digitalWrite(LED_BUILTIN, HIGH);   // enciende el LED (5v)
  delay(sensorValue);                // espera
  
  digitalWrite(LED_BUILTIN, LOW);    // apaga el LED (0v)
  delay(sensorValue);
}
