#define kapitani 12
#define switcheroo 6
#include <FastLED.h>
#include <Wire.h>
#include <DS3231.h>

RTClib myRTC;

#define LED_PIN     5
#define NUM_LEDS    54
#define BRIGHTNESS  235
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
CRGBPalette16 currentPalette;
TBlendType    currentBlending;


int paletteCounter = 0;
int hour0,hour1,hour2,hourm, minute0,minute1,minute2,minutem, second0,secondm;
int newhour, newminute, newsecond; //updated time for mania
int maniacounter =0; //rough af counter for mania control  
void setup() {
    pinMode(kapitani, INPUT);
    delay( 1500 ); // power-up safety delay
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
  Serial.println(digitalRead(switcheroo));
  
         if(digitalRead(switcheroo)==HIGH && digitalRead(kapitani)==LOW)
       {
            DateTime now = myRTC.now();
              hourm = now.hour();
              minutem = now.minute();
              secondm = now.second();
              if(maniacounter!=0)
              {
                //reset all time variables so they update again
                hour0=0;
                hour1=0;
                hour2=0;
                minute0=0;
                minute1=0;
                minute2=0;
                second0=0;
                maniacounter = 0; //reset maniacounter 
              }
              
        //    Troubleshooting
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
        
        if(now.hour() ==0)
           {
            LEDnumbers(0,0,1);
            LEDnumbers(0,13,1);
           }//this loop to make sure midnight hour lights up after party time
            
            if(hour0 !=now.hour())
            {
              hour0 = now.hour();
              for (int j = 0; j <=29; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
              hour1 = hour0/10;
              hour2 = hour0%10;
              LEDnumbers(hour1,0,1);
              LEDnumbers(hour2,13,1);
            }
            
            if(minute0 !=now.minute())
            {
              minute0 = now.minute();
              for (int j = 29; j <=55; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
              minute1 = minute0/10;
              minute2 = minute0%10;
              LEDnumbers(minute1,28,1);
              LEDnumbers(minute2,41,1);
            }
        
        
            //~~~~~~~~~~colon~~~~~~~~~~~~~~~~~~//
              if(second0 !=now.second())
            {
        
        //troubleshooting
            Serial.println("colon troubleshooting");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
        
        //troubleshooting end
        
              second0 = now.second();
              if(second0%2==0)
                    LEDnumbers(44,0,1);
                  else
                  LEDnumbers(404,0,0);
            }
        
            //~~~~~~~~~~colon end~~~~~~~~~~~~//
        minute0 = now.minute();
        hour0 = now.hour();//these 2 lines to make sure midnight party doesnt occur
        
           if(now.hour() ==0)
           {
            if(now.minute()==0)
            {
            SetupSynthwavePalette();
            for(int i = 0; i <=2; i++)
          {
            FillLEDsFromPaletteColors( i);
            if(i%5==0)
            {
                for (int j = 0; j <=55; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
            }
            FastLED.show();
            FastLED.delay(10000 / UPDATES_PER_SECOND);
          }
            }
           }  
        
                
         }
 Serial.print("mania?: ");
 Serial.println(digitalRead(kapitani));
 if(digitalRead(switcheroo)==HIGH && digitalRead(kapitani)==HIGH)//MANIA TIME
 {
  
  for (int j = 0; j <=55; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
                  FastLED.show();
                  FastLED.delay(10000 / UPDATES_PER_SECOND);
  maniacounter++;
  if(maniacounter<=25)
  {
    ManiaPhase(500,1);//number is delaytime btwn time increments
  }
    if(maniacounter>=25 )//53 second mark. keep speeding until we done
  {
    ManiaPhase(10,2);
  }
  

; }
}


//FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LEDnumbers(int num, int section, int color){
CRGB chosencolor;
//uint8_t brightness = 50;
switch(color)
{
  case 0: 
            chosencolor = CRGB::Black;
            break;
  case 1:
            chosencolor = CRGB::Orange;
            break;
  case 2:
            chosencolor = CRGB::Red;
            break;

  default:
            chosencolor = CRGB::Orange;
                     Serial.print("??: ");
                     break;
  
}
Serial.print("chosencolor: ");
Serial.println(chosencolor);

switch(num){
case 0:

            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[9+section] = chosencolor;
            leds[11+section] = chosencolor;

          
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11};
  return;
case 1:
            
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;

  FastLED.show();
  //numbers[] = {2,3,4,5,6};
  return;
case 2:
            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            
            leds[7+section] = chosencolor;
            leds[9+section] = chosencolor;
            
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,6,7,8,9,10,12};
  return;
case 3:
            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,10,12};
  return;
case 4:
            
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[11+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,2,3,4,5,6,10,11,12};
  return;
case 5:
            leds[1+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[11+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,4,5,6,7,8,10,11,12};
  return;
case 6:
            leds[1+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[9+section] = chosencolor;
            leds[11+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,4,5,6,7,8,9,10,11,12};
  return;
case 7:
            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6};
  return;
case 8:
            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[9+section] = chosencolor;
            leds[11+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
  return;
case 9:
            leds[1+section] = chosencolor;
            leds[3+section] = chosencolor;
            leds[5+section] = chosencolor;
            leds[7+section] = chosencolor;
            leds[11+section] = chosencolor;
            leds[12+section] = chosencolor;
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,10,11,12};
  return;

case 11:
  for (int i = 0; i <=12; i++)
          {
            leds[i+section] = CRGB::Black;
          }
  FastLED.show();
  //numbers[] = {0,1,2,3,4,5,6,7,8,9,10,11};
  return;

case 44:
  for (int i = 26; i <=27; i++)
          {
            leds[i] = chosencolor;
          }
  FastLED.show();
  //ON DOTS
  return;   

case 404:
  for (int i = 26; i <=27; i++)
          {
            leds[i] = CRGB::Black;
          }
  FastLED.show();
  //OFF DOTS
  return; 
  
default:
  for (int i = 0; i <=11; i++)
          {
            leds[i+section] = chosencolor;
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
    CRGB chosencolor  = CRGB::Green;
    CRGB deeppink  = CRGB::Blue;
    
    currentPalette = CRGBPalette16(
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink,
                                   red,  purple,  deeppink,  deeppink );
}

////////////////////////////////////////////////////////////////////////////
void ManiaPhase(int delaytime, int ledcolor)
{
//we recorded time of start with hourm, minutem & secondm
    if(hour0 ==0)
           {
            LEDnumbers(0,0,ledcolor);
            LEDnumbers(0,13,ledcolor);
           }//this loop to make sure midnight hour lights up after party time
            

              newhour = hourm;
              for (int j = 0; j <=29; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }

              hour1 = newhour/10;
              hour2 = newhour%10;
              LEDnumbers(hour1,0,ledcolor);
              LEDnumbers(hour2,13,ledcolor);

            

              newminute = minutem;
              for (int j = 29; j <=55; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
 
              minute1 = newminute/10;
              minute2 = newminute%10;
              LEDnumbers(minute1,28,ledcolor);
              LEDnumbers(minute2,41,ledcolor);

        
        
            //~~~~~~~~~~colon~~~~~~~~~~~~~~~~~~//
              if(newsecond !=secondm)
            {
        //troubleshooting
            Serial.print("colon troubleshooting: ");
            Serial.print(hourm);
            Serial.print(':');
            Serial.print(minutem);
            Serial.print(':');
            Serial.println(secondm);
        //troubleshooting end
        
              newsecond = secondm;
              if(newsecond%2==0)
                    LEDnumbers(44,0,ledcolor);
                  else
                  LEDnumbers(44,0,ledcolor);
            }
        
            //~~~~~~~~~~colon end~~~~~~~~~~~~//
        newminute = minutem;
        newhour = hour0;//these 2 lines to make sure midnight party doesnt occur
        
           if(newhour ==0)
           {
            if(newminute==0)
            {
            SetupSynthwavePalette();
            for(int i = 0; i <=110; i++)
          {
            FillLEDsFromPaletteColors( i);
            if(i%5==0)
            {
                for (int j = 0; j <=55; j++)
                  {
                    leds[j] = CRGB::Black;//blink to reset lights
                  }
            }
            FastLED.show();
            FastLED.delay(10000 / UPDATES_PER_SECOND);
          }
            }
           }
            FastLED.show(); //show entire clock
            FastLED.delay(10000 / UPDATES_PER_SECOND);
     
              if(minutem!=59)
              {
                minutem+=1;
              }
              else
              {
                minutem=0;
                  if(hourm!=23)
                  {
                    hourm+=1;
                  }
              }
           
           delay(delaytime);
}
