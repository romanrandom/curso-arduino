/**
 * Unidad 6: ProcessingJoystick
 */

int pinX = 0;
int pinY = 1;
int pinBoton = 3;

int x, y;

void setup() {
  
  Serial.begin(9600);

  pinMode(pinBoton, INPUT_PULLUP);
}

void loop() {

  x = analogRead(pinX);
  y = analogRead(pinY);

  Serial.print(x);
  Serial.print(",");
  Serial.println(y);
  delay(40);
}
