// Arduino stepper motor control code

#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 2038

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {

//  if (Serial.available()>0)
//  {
//    val = Serial.parseInt(); //how many steps to go for?
//    stepper.step(val); //get motor to run 'val' no. of steps
//    Serial.println(val); //for debugging
//  }

 stepper.setSpeed(3);
 stepper.step(-2038*0.0015); 
 stepper.setSpeed(4);
 stepper.step(-2038*0.002);
 stepper.setSpeed(5);
 stepper.step(-2038*0.0025);
 stepper.setSpeed(6);
 stepper.step(-2038*0.003);
 stepper.setSpeed(7);
 stepper.step(-2038*0.04); //get motor to run '' no. of steps
 stepper.setSpeed(6);
 stepper.step(-2038*0.0035); 
 stepper.setSpeed(5);
 stepper.step(-2038*0.0030); 
 stepper.setSpeed(4);
 stepper.step(-2038*0.0025); 
 stepper.setSpeed(3);
 stepper.step(-2038*0.0015); 
 stepper.setSpeed(2);
 stepper.step(-2038*0.001); 


 stepper.setSpeed(3);
 stepper.step(2038*0.0015); 
 stepper.setSpeed(4);
 stepper.step(2038*0.002); 
 stepper.setSpeed(5);
 stepper.step(2038*0.0025); 
 stepper.setSpeed(6);
 stepper.step(2038*0.003); 
 stepper.setSpeed(7);
 stepper.step(2038*0.04); //get motor to run '' no. of steps
 stepper.setSpeed(6);
 stepper.step(2038*0.0035); 
 stepper.setSpeed(5);
 stepper.step(2038*0.003); 
 stepper.setSpeed(4);
 stepper.step(2038*0.0025); 
 stepper.setSpeed(3);
 stepper.step(2038*0.0015); 
 stepper.setSpeed(2);
 stepper.step(2038*0.001); 
 

}
