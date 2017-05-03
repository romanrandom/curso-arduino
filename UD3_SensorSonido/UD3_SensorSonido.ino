int LED = 13; 
int sensor = 8;
bool estado = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  digitalWrite(LED, LOW);         // Apagamos el LED al empezar

  Serial.begin(9600);
}

void loop() {
  
  int valor = analogRead(A0);
  Serial.println(valor);
  
  bool on =  digitalRead(sensor) ; //leemos el estado del sensor
  if ( on == true ) //Si está activada la salida D0
  {
    estado = ! estado ;                       // cambiamos el estado del LED
    digitalWrite(LED, estado) ;            // escribimos el nuevo valor
  }
}
