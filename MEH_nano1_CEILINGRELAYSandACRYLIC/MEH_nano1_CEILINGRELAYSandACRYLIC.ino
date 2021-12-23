#define kapitani 12
#define switcheroo 6

//ACRYLIC PANELS~~~~~
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

//ACRYLIC PANELS END~~~~~

int ch1 = 3;           // channel 1 of relay, pin D3 of arduino
int ch2 = 4;           // channel 2 of relay, pin D4 of arduino


void setup() {
  pinMode(switcheroo, INPUT);
  pinMode(kapitani, INPUT);

  pinMode(ch1, OUTPUT);
  pinMode(ch2, OUTPUT);

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
  Serial.begin(9600);

}
//LOOOOOOOOOOOOOOPPPPPPPPP
void loop() {
  Serial.print("switcheroo: ");
  Serial.println(digitalRead(switcheroo));
  if( digitalRead(switcheroo) == HIGH)//on/off switch triggered
  {
    ceilingonoff(0);
    Serial.print("digital: ");
    Serial.println(digitalRead(kapitani));
    while(digitalRead(kapitani)==HIGH)//MANIA TIME
      {
        for(int i=1; i<=5;i++)
        {
        ceilingonoff(1);
        delay(500);
        ceilingonoff(0);
            if (digitalRead(kapitani)==LOW)
            {break;}
        LEDframes(0,1);
        LEDframes(17,3);
        LEDframes(34,3);
        LEDframes(52,3);
            if (digitalRead(kapitani)==LOW)
            {break;}
        delay(10);
        }
        
        for(int i=1; i<=5;i++) //speed up
        {
        ceilingonoff(1);
        delay(400);
        ceilingonoff(0);
            if (digitalRead(kapitani)==LOW)
            {break;}
        LEDframes(0,111);
        LEDframes(17,11);
        LEDframes(34,11);
        LEDframes(52,11);
            if (digitalRead(kapitani)==LOW)
            {break;}
        ceilingonoff(1);
        
        LEDframes(0,44);
        LEDframes(17,4);
        LEDframes(34,4);
        LEDframes(52,4);
        delay(200);
            if (digitalRead(kapitani)==LOW)
            {break;}
        ceilingonoff(0);
        delay(300);
        ceilingonoff(1);
        delay(10);
        }
        
        for(int i=1; i<=5;i++) //SPEEDIEST BOY
        {
        LEDframes(0,111);
        LEDframes(17,11);
        LEDframes(34,11);
        LEDframes(52,11);
                if (digitalRead(kapitani)==LOW)
                {break;}
        ceilingonoff(1);
        delay(300);
                if (digitalRead(kapitani)==LOW)
                {break;}
        ceilingonoff(0);
        ceilingonoff(1);
        LEDframes(0,1);
        LEDframes(17,3);
        LEDframes(34,3);
        LEDframes(52,3);
        delay(100);
        ceilingonoff(0);
                if (digitalRead(kapitani)==LOW)
                {break;}
        ceilingonoff(1);
        delay(100);
        ceilingonoff(0);
        delay(10);   
        LEDframes(0,22);
        delay(10); 
      }

      
  if(digitalRead(kapitani)==HIGH )//hand TIME
    {
      ceilingonoff(0);     
      LEDframes(0,404);
      LEDframes(17,404);
      LEDframes(34,404);
      LEDframes(52,404);
    }
  
    
    

    }
 
}
}

//FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ceilingonoff(int i)
{
  if (i == 0)//OFF
  {
    digitalWrite(ch1, LOW);
    digitalWrite(ch2, LOW);
    Serial.println(0);
  }
  else if (i ==1)//ON
  {
    digitalWrite(ch1,HIGH);
    digitalWrite(ch2,HIGH);
    Serial.println(1);
  }
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
      case 44:
              for(int i =16; i>=0; i--)
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
        for (int i = 0; i <=80; i++)
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
