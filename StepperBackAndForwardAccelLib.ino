#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1, 9, 8);

int pos = 1600;

void setup()
{  
  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(2000);
}

void loop()
{
  digitalWrite(4, HIGH);
  if (stepper.distanceToGo() == 0)
  {
    delay(500);
    pos = -pos;
    stepper.moveTo(pos);
  }
  stepper.run();
}
