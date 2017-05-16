import processing.serial.*;

Serial serie;
String recibido;

float x = 0;
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
      x = float(recibido);
    }
  }
  
  background(0, 100, 0);
  
  float xm = map(x, 0, 1023, 0, width);
  //println(x);
  fill(255, 0, 0);
  ellipse(xm, height/5 + 150*noise(millis()/1000f), 10, 10);
}