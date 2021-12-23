#define kapitani 12
#define kapitano A3
#define switcheroo 6
#include <Stepper.h> // Include the header file


//ULTRASONIC VARIABLES~~~~~~~~~~~~~~~~
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

#define echoH 5 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigH 4 //attach pin D3 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
//ULTRASONIC VARIABLES ENDDDD~~~~~~~~~~~~~~~~

//HAND LIGHTS~~~~~
#include <FastLED.h>

#define LED_PIN     7
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
  pinMode(switcheroo, INPUT);
  pinMode(kapitani, INPUT);
  pinMode(kapitano, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(trigH, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoH, INPUT); // Sets the echoPin as an INPUT
  stepper.setSpeed(15);

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

  
}

//LOOOOOOOOOOOOOOPPPPPPPPP
void loop() {
Serial.println(digitalRead(switcheroo));
if (digitalRead(switcheroo) == HIGH)//start button triggered
{
  SetupSynthwavePalette();
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(1);
  
int hand = handtrig();
Serial.print("RESTART - current distance: ");
Serial.print(hand);
Serial.println("cm");

if (hand<50)
  {
  analogWrite(kapitano, 200);
  if(handtrig()<50)
    {
      
      blindsopen();
    }
  
  }
else
{
   analogWrite(kapitano, 24);
      while(handtrig()>50) 
    {
      blindsclose();
    }
}

}
else
{
  Serial.println("lights out");
}

}


//FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int distcalc()
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor for troubleshooting
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
  
}

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
  Serial.print("hand distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void blindsopen()
{
  Serial.println("wakey wakey it's time for school");
  if (distcalc()<=15) 
  {
  stepper.step(2038*0.5); //get motor to run '' no. of steps
  }
}

void blindsclose()
{
  Serial.println("nighty nite");
  if (distcalc()>=9)  
  {
  stepper.step(-2038*0.5); //get motor to run '' no. of steps
  }
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 40;
    
    for( int i = 0; i <=NUM_LEDS-1; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);

        colorIndex += 1;
    }
}

void SetupSynthwavePalette()
{
    CRGB red  = CRGB::Red ;
    CRGB orange = CRGB::DarkOrange;
    CRGB yellow  = CRGB::Yellow;
    CRGB yellowgreen  = CRGB::YellowGreen ;
    
    currentPalette = CRGBPalette16(
                                   red,  orange,  yellow,  yellowgreen,
                                   red,  orange,  yellow,  yellowgreen,
                                   red,  orange,  yellow,  yellowgreen,
                                   red,  orange,  yellow,  yellowgreen);
}

void SetupHandPalette()
{
    CRGB lightyellow  = CRGB::LightYellow ;
    CRGB orange = CRGB::DarkOrange;
    CRGB yellow  = CRGB::Yellow;
    CRGB yellowgreen  = CRGB::PaleGoldenrod ;
    
    currentPalette = CRGBPalette16(
                                   lightyellow,  orange,  yellow,  yellowgreen,
                                   lightyellow,  orange,  yellow,  yellowgreen,
                                   lightyellow,  orange,  yellow,  yellowgreen,
                                   lightyellow,  orange,  yellow,  yellowgreen);
}
