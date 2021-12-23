#define kapitani 12
#define switcheroo 6
int startflag=0;
//MOTOR CODE~~~~~~~~~~~//
#include <Stepper.h> // Include the header file
// change this to the number of steps on your motor
#define STEPS 2038
// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

//MOTOR CODE END~~~~~~~//


int ch1 = 2; //channel 1 of SSR, pin D2 of arduino
int triggerType = LOW;// LOW if ssr is low level trigger. vice versa for high level trigger
int ssrON, ssrOFF;// used for two different SSR trigger type. Do not change

void setup() {
  Serial.begin(9600);
  pinMode(switcheroo, INPUT);
  pinMode(kapitani, INPUT);
  pinMode(ch1, OUTPUT);//define ch1Pin as output
  stepper.setSpeed(15);
  if(triggerType == LOW)
    {
      ssrON = LOW;
      ssrOFF = HIGH;
    }
  else
    {
      ssrON = HIGH;
      ssrOFF = LOW; //if trigger type is HIGH
    }
  digitalWrite(ch1,ssrON);// set initial state of SSR 1: ON
}

//LOOOOOOOOOOOOOOPPPPPPPPP
void loop() {
  Serial.println(digitalRead(switcheroo));
  if (digitalRead(switcheroo) == HIGH)
{
   stepper.step(-2038*0.2); //get motor to run '' no. of steps
   stepper.step(2038*0.2); //get motor to run '' no. of steps   
  Serial.print("kapitan: ");
  Serial.println(digitalRead(kapitani));
      if (digitalRead(kapitani ==HIGH) )
      {
        stepper.setSpeed(18);
        digitalWrite(ch1,ssrON);// turn lamp on
        stepper.step(-2038*0.2); //get motor to run '' no. of steps
        stepper.step(2038*0.2); //get motor to run '' no. of steps
        digitalWrite(ch1,ssrOFF);// turn lamp off
        stepper.step(-2038*0.2); //get motor to run '' no. of steps
        stepper.step(2038*0.2); //get motor to run '' no. of steps
      }
      if (analogRead(kapitani ==3) || analogRead(kapitani ==42))
      {
        stepper.setSpeed(15);
        stepper.step(-2038*0.2); //get motor to run '' no. of steps
        stepper.step(2038*0.2); //get motor to run '' no. of steps 
      }
  }
}
