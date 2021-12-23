// Arduino stepper motor control code
#define kapitani A2
#define kapitano A3
#define switcheroo 6
#include <Stepper.h> // Include the header file
//ULTRASONIC VARIABLES~~~~~~~~~~~~~~~~
#define echo 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trig 2 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoH 5 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigH 4 //attach pin D3 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
//ULTRASONIC VARIABLES ENDDDD~~~~~~~~~~~~~~~~

//HAND LIGHTS~~~~~
#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    6
#define BRIGHTNESS  40
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
int counter =0;
int paletteCounter = 0;
//HAND LIGHTS END~~~~~

#define STEPS 2038  //number of steps on motor

// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigH, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoH, INPUT); // Sets the echoPin as an INPUT
  pinMode(switcheroo, INPUT);
  pinMode(kapitani, INPUT);
  pinMode(kapitano, OUTPUT);
  stepper.setSpeed(15);

  delay( 3000 ); // power-up safety delay
  
}
void loop() {
  

  handtrig();
}




//functions

int handtrig()
{
// Clears the trigPin condition
  digitalWrite(trigH, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigH, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigH, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoH, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor for troubleshooting
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
  
}
