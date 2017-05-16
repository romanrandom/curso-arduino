/** 
 *  Unidad 4: Interrupciones con Debounce
 *  
 *  
 */

volatile int contador = 0;   // "volatile" se usa para indicar al programa 
                             // que esta variable puede ser manipulada desde fuera 
                             // y también indicar al compilador que no la elimine
                             // al optimizar código por no ser usada dentro del programa
int n = contador;

long t = 0;                 // Variable global para tiempo

void setup() {    

  Serial.begin(9600);
  Serial.println("Dale!"); 
  pinMode(2, INPUT_PULLUP);
  attachInterrupt( 0, incrementaContador, LOW);
} 

void loop() {   
  if (n != contador) {   
    Serial.println(contador);
    n = contador;
  }
}

void incrementaContador() {
  
  // El valor que devuelve millis() se congela hasta salir del callback 
  if ( millis() > (t + 50) ) {
    contador++ ;
    t = millis();
  }
}
