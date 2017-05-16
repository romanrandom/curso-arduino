volatile int contador = 0;   // Para evitar problemas con conflictos
int n = contador;

long t = 0;                 // Variable global para tiempo

void setup() {    

  Serial.begin(9600); 
  pinMode(2, INPUT_PULLUP);
  attachInterrupt( 0, incrementaContador, LOW);
} 

void loop() {   
  if (n != contador) {   
    Serial.println(contador);
    n = contador;
  }
  delay(3000);
}

void incrementaContador() {
  // El valor que devuelve millis() se congela hasta salir del callback 
  if ( millis() > (t + 50) ) {
    contador++ ;
    t = millis();
  }
}
