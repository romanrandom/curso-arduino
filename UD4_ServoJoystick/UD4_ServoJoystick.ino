/**
 * Unidad 4: Servo con joystick
 */

#include <Servo.h>             

Servo servo;                   // Crear un objeto tipo Servo llamado servo

int angulo = 0;               
int pinX = A1;
int pinY = A2;

void setup() {
  servo.attach(6);
}

void loop() {
  
  int ejeX = analogRead(pinX);

  angulo = ejeX - 512;                      // Con esta operación conseguimos tener valores entre -512 y 511
  if (abs(angulo) < 50) angulo = 0;         // Filtramos movimientos pequeños del joystick
  angulo = map(angulo, -512, 511, 0, 180);  // Mapeamos los valores a grados
 
  servo.write(angulo);
  
}
