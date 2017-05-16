int x = 0;
boolean direccion = true;

void setup() {
  size(400, 400);
  //background(0, 100, 0);
  noStroke();
  //ellipse(width/3, height/2, 10, 18);
}


void draw() {
  
  //background(0, 100, 0);
  fill(0, 50, 0, 50);
  rect(0, 0, width, height);
  
    
  fill(255, 80);
  rect(0, x, width, height);
  
  x += (direccion ? 2 : -4);
  
  //println(x);
  
  if (x >= width || x < 0) {
    direccion = !direccion;
    
  }
  
  if (x >= width) {
    x = width;
  } else if (x < 0) {
    x = 0;
  }
  
  fill(random(50,255), 0, 0, 90);
  ellipse(x, height/5 + 150*noise(millis()/1000f), 10, 10);
}