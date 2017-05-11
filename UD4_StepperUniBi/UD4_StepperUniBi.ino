/**
 * Unidad 4: StepperUnipolaraBipolar
 * 
 * Usando el stepper unipolar conectado como bipolar y el L293D
 * haremos que gire usando la librería Stepper incluida con el Arduino
 */
  

#include <Stepper.h>

const int in1Pin = 12;
const int in2Pin = 11;
const int in3Pin = 10;
const int in4Pin = 9;

#define STEPS 512  // Define el numero de pasos del motor. 512 para el 28BYJ-48

Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  Serial.begin(115200);
  motor.setSpeed(40);     // Fijar la velocidad en rpms
}

void loop() {
  if (Serial.available()) {
    int steps = Serial.parseInt();
    Serial.print("Moviendo ");
    Serial.print(steps);
    Serial.println(" pasos");
    motor.step(steps);
  }
}
