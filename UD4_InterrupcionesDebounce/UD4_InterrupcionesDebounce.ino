volatile int contador = 0;   // Para evitar problemas con conflictos
int n = contador;

long t = 0;                 // Variable global para tiempo

void setup() {    
  pinMode(2, INPUT);
  Serial.begin(9600); 
  attachInterrupt( 0, incrementaContador, LOW);
} 

void loop() {   
  if (n != contador) {   
    Serial.println(contador);
    n = contador ;
  }
}

void incrementaContador() {
  // El valor que devuelve millis() se congela hasta salir del callback 
  if (millis() > t + 50) {
    contador++ ;
    t = millis();
  }
}
