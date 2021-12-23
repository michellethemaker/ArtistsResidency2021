#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    68
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

int counter =0;
int paletteCounter = 0;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    Serial.begin(9600);
}

void loop() {
  
     
    Serial.println("EXECUTE");   
    
    
    LEDframes(0,1);
    delay(100);
    LEDframes(17,3);
    delay(100);
    LEDframes(34,3);
    delay(100);
    LEDframes(52,41);
    delay(100);

    LEDframes(0,111);
    delay(100);
    LEDframes(17,11);
    delay(100);
    LEDframes(34,11);
    delay(100);
    LEDframes(52,11);
    delay(100);   


    LEDframes(0,22);
    delay(100);
//    LEDframes(17,22);
//    delay(100);
//    LEDframes(34,22);
//    delay(100);
//    LEDframes(52,22);
//    delay(100);

    }



void LEDframes(int section, int mode){

//uint8_t brightness = 50;
CRGB blue = CRGB::DeepPink;
CRGB black = CRGB::Black;
CRGB white = CRGB::White;
CRGB green = CRGB::Green;
CRGB orange = CRGB::Orange;

switch(mode){
case 1:
      for(int i =16; i>=0; i--)
      {
      
            leds[i+section] = white;
            FastLED.show();
            delay(10);
      }
          
  
  return;
case 2:
       for(int i =0; i<=16; i++)
            {
            
                  leds[i+section] = green;
                  FastLED.show();
            delay(20);
            }
  
  return;
case 3:
      for(int i =0; i<=16; i++)
            {
            
                  leds[i+section] = white;
                  FastLED.show();
             delay(20);
            }
  
  return;
case 4:
        for(int i =0; i<=16; i++)
              {
              
                    leds[i+section] = orange;
                    FastLED.show();
            delay(20);
              }
  return;

case 11:
          for(int i =0; i<=16; i++)
                      {
                      
                            leds[i+section] = black;
                            FastLED.show();
            delay(20);
                      }
  
  return;

case 111:
          for(int i =16; i>=0; i--)
                      {
                      
                            leds[i+section] = black;
                            FastLED.show();
            delay(20);
                      }
  
  return;

case 22:
  for(int i =0; i<=40; i++ ) {
          for(int j = 0; j < NUM_LEDS; j++)
                  {
                    FastLED.setBrightness(  i );
                    leds[j] = CRGB::Orange;
                  }
                  FastLED.show();
                    delay(20);
  }
  for(int i =40; i>=0; i-- ) {
          for(int j = 0; j < NUM_LEDS; j++)
                  {
                    FastLED.setBrightness(  i );
                    leds[j] = CRGB::Orange;
                  }
                  FastLED.show();
                    delay(20);
  }
  for(int i =0; i<=40; i++ ) {
          for(int j = 0; j < NUM_LEDS; j++)
                  {
                    FastLED.setBrightness(  i );
                    leds[j] = CRGB::Orange;
                  }
                  FastLED.show();
                    delay(20);
  }
  //brghtness change
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

Serial.print(mode);
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
    uint8_t brightness = 100;
    
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
