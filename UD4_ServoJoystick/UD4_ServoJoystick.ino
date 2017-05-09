#include <Servo.h>             
Servo servo;                   // Crear un objeto tipo Servo llamado servo
int angulo = 90;               // Empezamos en el centro
int pinX = A1;
int pinY = A2;

void setup() {
  servo.attach(6);
}

void loop() {
  int ejeX = analogRead(pinX);

  angulo = ejeX - 512;
  if (abs(angulo) < 50) angulo = 0;
  angulo = map(angulo, -511, 511, 0, 180);
 
  servo.write(angulo);
  
}
