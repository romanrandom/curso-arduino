import processing.serial.*;

Serial serie;
String recibido;

String posicion[];
int x, y;
boolean direccion = true;

void setup() {
  
  size(400, 400);
  noStroke();
  printArray(Serial.list());
  String puerto = Serial.list()[3];
  serie = new Serial(this, puerto, 9600);
}

void draw() {
  
  if ( serie.available() > 0) {  // If data is available,
    //x = serie.read();         // read it and store it in val
    recibido = serie.readStringUntil(13);
    
    if (recibido != null) {
      
      posicion = split(recibido, ',');
      
      if (posicion.length == 2) {
        y = int( map(float(posicion[1]), 0, 1023, 0, height) );
        x = int( map(float(posicion[0].trim()), 0, 1023, 0, width) );
      }
      
           
 
    }
  }
  
  background(0, 100, 0);

  fill(255, 0, 0);
  ellipse(x, y, 10, 10);
}