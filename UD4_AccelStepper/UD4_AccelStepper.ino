#include <AccelStepper.h>
#define HALFSTEP 8

// Definiciones de los pines del motor
#define motorPin1  8
#define motorPin2  9    
#define motorPin3  10     
#define motorPin4  11     

// Inicializa la secuencia de los pines IN1-IN3-IN2-IN4 para usar AccelStepper con el 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(1000.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(10000);

}

void loop() {

  //C Cambia la dirección cuando el motor llega a su posición de destino
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
}
