/**
 * Unidad 4: Interrupciones
 * 
 */

int contador = 0;
int n = contador;

void setup() {   
  
  Serial.begin( 9600 );
  
  pinMode(2, INPUT_PULLUP); // Para que funcione la interrupción, esta línea tiene que ir antes
  attachInterrupt( 0, incrementaContador, FALLING );
}

void loop() {
  
  if ( n != contador ) {
    Serial.println( contador );
    n = contador;
  }
}

void incrementaContador() {    
  contador++;
}
