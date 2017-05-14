/**
 * Unidad 4: Operaciones binarias
 * 
 * Usando las constantes predefinidas DDRD (pinMode de los pines digitales)
 * y PORTD (estado de los pines digitales) vemos la utilidad
 * de las operaciones binarias &, | y <<
 */

int i;     // variables para el bucle for
int j;

void setup(){

  // Mediante un OR binario configura la dirección de los bits para los pines 2 a 7
  // sin cambiar los pines 0 y 1.
  // Equivale a pinMode(pin, OUTPUT) para los pines del 2 al 7
  DDRD = DDRD | B11111100;
  
  Serial.begin(9600);
}

void loop(){
  
  for (i = 0; i < 64; i++) {
  
    PORTD = PORTD & B00000011;  // pone a 0 lo bits 2 - 7, no cambia el 0 y 1
    j = (i << 2);               // desploaza hacia la izquierda (arriba) hasta los pines 2 a 7 (evitamos el 0 y 1)
    PORTD = PORTD | j;          // combina la nueva información de estados con lo que había en PORTD
    Serial.println(PORTD, BIN); // muestra la máscara por el monitor serie
    delay(100);
  }
  
}
