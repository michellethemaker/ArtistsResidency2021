#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    54
#define BRIGHTNESS  140
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

int counter =0;
int paletteCounter = 0;
//int num4 = 0, num3 = 0, num2 = 0, num1=3;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    Serial.begin(9600);
}

void loop() {
  
    FastLED.clear();
    fill_solid( currentPalette, 16, CRGB::Black);
    FastLED.show();
    FastLED.delay(8000 / UPDATES_PER_SECOND);
    
    Serial.println("EXECUTE");   
    
    
    LEDnumbers(3,0);
    LEDnumbers(0,13);
    LEDnumbers(0,28);
    LEDnumbers(0,41);
    delay(1000);

 
    for(int num1=0;num1<3; num1++)
    {
      
    for(int num2=9; num2>=0; num2--){
      
            LEDnumbers(11,0);
            LEDnumbers(11,13);
            LEDnumbers(2-num1,0);
            LEDnumbers(num2,13);

      for(int num3=0; num3<6; num3++)
      {
        Serial.print(5-num3);
        Serial.println(" FIRSTseconds");
            LEDnumbers(11,28);
            LEDnumbers(5-num3,28);
        for(int num4 = 9; num4>=0; num4--)
        {
          //~~~~~~~~~~colon~~~~~~~~~~~~~~~~~~//
          counter++;
          if(counter%2==0)
            LEDnumbers(44,0);
          else
          LEDnumbers(404,0);
          //~~~~~~~~~~colon~~~~~~~~~~~~~~~~~~//
          
          Serial.print(num4);
          Serial.println(" SECONDseconds");
          
            
            LEDnumbers(11,41);
            
            LEDnumbers(num4,41);
            
        delay(1000);
        
        
        }
      }
      
 
    }
    }//end of 30 minutes!

ChangePalettePeriodically();
  for(int i = 0; i <=200; i++)
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



void LEDnumbers(int num, int section){

//uint8_t brightness = 50;
CRGB blue = CRGB::DeepPink;
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
    uint8_t brightness = 230;
    
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
