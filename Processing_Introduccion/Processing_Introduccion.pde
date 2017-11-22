int posicionX = 0;
int velocidadX = 1; // Números positivos hacia la derecha, negativos hacia la izquierda
int ancho = 100;

void setup() {  
   
   size( 250, 250 );
   ellipseMode( CORNER );
}

void draw() {
    
    background( 41, 206, 104 );
    stroke( 150 );
    strokeWeight( 5 );
    fill( 0 );
    rect( posicionX, 30, ancho, ancho );
    

    posicionX = posicionX + velocidadX;
    
    if ( posicionX == width - ancho ) {
        velocidadX = -1;
    } else if ( posicionX == 0 ) {
        velocidadX = 1;
    }
    
    fill( 0, 100 );
    ellipse( width - posicionX - ancho, 100, ancho, ancho );
    
}