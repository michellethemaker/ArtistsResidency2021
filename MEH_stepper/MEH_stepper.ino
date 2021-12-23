// Arduino stepper motor control code

#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 2038

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(15);
}

void loop() {

//  if (Serial.available()>0)
//  {
//    val = Serial.parseInt(); //how many steps to go for?
//    stepper.step(val); //get motor to run 'val' no. of steps
//    Serial.println(val); //for debugging
//  }
 stepper.step(2038*2.5); //get motor to run '' no. of steps
 
 stepper.step(-2038*2.5); //get motor to run '' no. of steps

 

}
