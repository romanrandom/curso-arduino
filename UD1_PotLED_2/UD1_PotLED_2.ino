void setup() {

  pinMode( LED_BUILTIN, OUTPUT ); // En el Arduino UNO, poner LED_BUILTIN equivale a poner 13

  Serial.begin( 9600 );
  
}

void loop() {
    
  int retardo = analogRead( A0 ); // La A no es necesaria

  retardo = map( retardo, 20, 700, 100, 500 ); // ( valor a cambiar, mínimo inicial, máximo inicial, mínimo final, máximo final )
  Serial.println( retardo ); 
  
  digitalWrite(LED_BUILTIN, HIGH);   // enciende el LED (5v)
  delay(retardo);                    // espera
  
  digitalWrite(LED_BUILTIN, LOW);    // apaga el LED (0v)
  delay(retardo);                    // espera

}
