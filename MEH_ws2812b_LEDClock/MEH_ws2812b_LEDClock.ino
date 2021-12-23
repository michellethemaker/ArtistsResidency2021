#include <FastLED.h>
#include <Wire.h>
#include <DS3231.h>

RTClib myRTC;

#define LED_PIN     5
#define NUM_LEDS    54
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
CRGBPalette16 currentPalette;
TBlendType    currentBlending;


int paletteCounter = 0;
int hour,hour1,hour2, minute,minute1,minute2, second;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    Wire.begin();
    Serial.begin(9600);
    FastLED.clear();
    fill_solid( currentPalette, 16, CRGB::Black);
    FastLED.show();
}

void loop() {
    DateTime now = myRTC.now();
    
if(now.hour() ==0)
   {
    LEDnumbers(0,0);
    LEDnumbers(0,13);
   }//this loop to make sure midnight hour lights up after party time
    
    if(hour !=now.hour())
    {
      hour = now.hour();
      for (int j = 0; j <=29; j++)
          {
            leds[j] = CRGB::Black;
          }
      hour1 = hour/10;
      hour2 = hour%10;
      LEDnumbers(hour1,0);
      LEDnumbers(hour2,13);
    }
    
    if(minute !=now.minute())
    {
      minute = now.minute();
      for (int j = 29; j <=55; j++)
          {
            leds[j] = CRGB::Black;
          }
      minute1 = minute/10;
      minute2 = minute%10;
      LEDnumbers(minute1,28);
      LEDnumbers(minute2,41);
    }


    //~~~~~~~~~~colon~~~~~~~~~~~~~~~~~~//
      if(second !=now.second())
    {

//troubleshooting

    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

//troubleshooting end

      second = now.second();
      if(second%2==0)
            LEDnumbers(44,0);
          else
          LEDnumbers(404,0);
    }

    //~~~~~~~~~~colon end~~~~~~~~~~~~//
minute = now.minute();
hour = now.hour();//these 2 lines to make sure midnight party doesnt occur

   if(now.hour() ==0)
   {
    if(now.minute()==0)
    {
    ChangePalettePeriodically();
    for(int i = 0; i <=110; i++)
  {
    FillLEDsFromPaletteColors( i);
    if(i%5==0)
    {
        for (int j = 0; j <=55; j++)
          {
            leds[j] = CRGB::Black;
          }
    }
    FastLED.show();
    FastLED.delay(10000 / UPDATES_PER_SECOND);
  }
    }
   }  
        
        
}



void LEDnumbers(int num, int section){

//uint8_t brightness = 50;
CRGB blue = CRGB::Orange;
CRGB black = CRGB::Black;

switch(num){
case 0:

            leds[1+section] = blue;
            leds[3+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[9+section] = blue;
            leds[11+section] = blue;

          
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11};
  return;
case 1:
            
            leds[3+section] = blue;
            leds[5+section] = blue;

  FastLED.show();
  //numbers[] = {2,3,4,5,6};
  return;
case 2:
            leds[1+section] = blue;
            leds[3+section] = blue;
            
            leds[7+section] = blue;
            leds[9+section] = blue;
            
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,6,7,8,9,10,12};
  return;
case 3:
            leds[1+section] = blue;
            leds[3+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,10,12};
  return;
case 4:
            
            leds[3+section] = blue;
            leds[5+section] = blue;
            leds[11+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,2,3,4,5,6,10,11,12};
  return;
case 5:
            leds[1+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[11+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,4,5,6,7,8,10,11,12};
  return;
case 6:
            leds[1+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[9+section] = blue;
            leds[11+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,4,5,6,7,8,9,10,11,12};
  return;
case 7:
            leds[1+section] = blue;
            leds[3+section] = blue;
            leds[5+section] = blue;
            
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6};
  return;
case 8:
            leds[1+section] = blue;
            leds[3+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[9+section] = blue;
            leds[11+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
  return;
case 9:
            leds[1+section] = blue;
            leds[3+section] = blue;
            leds[5+section] = blue;
            leds[7+section] = blue;
            leds[11+section] = blue;
            leds[12+section] = blue;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,10,11,12};
  return;

case 11:
  for (int i = 0; i <=12; i++)
          {
            leds[i+section] = black;
          }
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11};
  return;

case 44:
  for (int i = 26; i <=27; i++)
          {
            leds[i] = blue;
          }
  FastLED.show();
  //ON DOTS
  return;   

case 404:
  for (int i = 26; i <=27; i++)
          {
            leds[i] = black;
          }
  FastLED.show();
  //OFF DOTS
  return; 
  
default:
  for (int i = 0; i <=11; i++)
          {
            leds[i+section] = blue;
          }
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11};
  return;
  Serial.println("wtf where number");
  return;
}

Serial.print(num);
Serial.println(" is the number");

}

void ChangePalettePeriodically()
{    
    if( paletteCounter == 0)   {  SetupSynthwavePalette();  currentBlending = LINEARBLEND; }
    if( paletteCounter == 1)   {  SetupSynthwavePalette(); } //REMOVE TO REENABLE TOGGLE AND UNCOMMENT NEXT LINE
   // if( paletteCounter == 1)   {  SetupOFFPalette();   currentBlending = LINEARBLEND; } //COMMENTED OUT TO STOP TOGGLING
    }


void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = NUM_LEDS-1; i >=0; i--) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);

        colorIndex += 3;
    }
}

void SetupSynthwavePalette()
{
    
    CRGB red  = CRGB::Red ;
    CRGB purple = CRGB::DarkOrange;
    CRGB blue  = CRGB::Green;
    CRGB deeppink  = CRGB::Blue;
    
    currentPalette = CRGBPalette16(
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink );
}
