/**
 * Unidad 4: Stepper
 * 
 */

const byte fases = 4;

const float anguloPorPaso = 5.625;
const float reduccion = 64;
const int pasosPorVuelta = 360 / anguloPorPaso * reduccion;

const float vueltas = 1.5;   // Número de vueltas que queremos que gire

const float pasosTotales = vueltas * pasosPorVuelta;

// Usamos una secuencia tipo "wave"
const int pasos = 8;
int paso[ pasos ][ fases ] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

const byte bobina[] = { 11, 10, 9, 8 };

int pasosRestantes = pasosTotales;
bool direccion = true;

int pasoActual = 0;


void setup() {

  for ( int i = 0; i < fases; i++ ) {
    pinMode( bobina[ i ], OUTPUT );
  }

}

void loop() {
  
  while( pasosRestantes > 0 ) {
    mueve();
    pasosRestantes--;
    delay( 1 );
  }

  delay( 100 );
  
  direccion = !direccion;
  pasosRestantes = pasosTotales;

}


void mueve() {
  
  for ( int i = 0; i < fases; i++ ) {
    digitalWrite( bobina[ i ], paso[ pasoActual ][ i ]);
  }

  siguientePaso();
}

void siguientePaso() {  
  
  if ( direccion ) {
    pasoActual++;
  } else {
    pasoActual--;
  }

  pasoActual = ( pasoActual + pasos ) % pasos;    // Nos aseguramos de que se queda entre 0 y número de pasos
}


