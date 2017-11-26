const byte pin = 2;

void setup() {
  
  pinMode(pin, INPUT_PULLUP); // Activa la resistencia interna que lo deja a 5V
  
  Serial.begin(9600);
  
}

void loop() {
  
  Serial.println( digitalRead(pin) ); // Lee el estado del pin y lo manda por el puerto serie
  // Tendremos un 1 (5v) sin pulsar y un 0 (0v) al pulsar
  
}
