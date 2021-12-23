#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    65
#define BRIGHTNESS  245
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 10

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

int paletteCounter = 0;
//int vibsens_pin=9;//vib sensor
//int viber_pin  =6;//micro vibrator


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
//    pinMode(vibsens_pin,INPUT);
  //  pinMode(viber_pin,OUTPUT);
//    Serial.begin(9600);
    
}


void loop()
{
    Serial.println("EXECUTE");
   

       
//switch(digitalRead(vibsens_pin)){
//    case 1:    
//      paletteCounter++;
//      if (paletteCounter > 1)
//        { // adjust if you have more or less than 2 palettes
//        paletteCounter = 0;
//        }
//     
//      Serial.println("TRIGGERED");
//      break;
//    default:
//      break;
//}

 ChangePalettePeriodically();       
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(100);

   
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 40;
    
    for( int i = 0; i <=NUM_LEDS-1; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);

        colorIndex += 1;
    }
}

void ChangePalettePeriodically()
{    
    if( paletteCounter == 0)   {  SetupSynthwavePalette();  currentBlending = LINEARBLEND; }
    if( paletteCounter == 1)   {   } //REMOVE TO REENABLE TOGGLE AND UNCOMMENT NEXT LINE
   // if( paletteCounter == 1)   {  SetupOFFPalette();   currentBlending = LINEARBLEND; } //COMMENTED OUT TO STOP TOGGLING
    }
// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.




void SetupOFFPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
}

// This function sets up a palette of purple and green and aqua stripes.
void SetupSynthwavePalette()
{
    CRGB red  = CRGB::Red ;
    CRGB purple = CRGB::DarkOrange;
    CRGB blue  = CRGB::Blue;
    CRGB deeppink  = CRGB::Purple;
    
    currentPalette = CRGBPalette16(
                                   red,  purple,  blue,  deeppink,
                                   red,  purple,  blue,  deeppink,
                                   red,  purple,  blue,  deeppink,
                                   red,  purple,  blue,  deeppink );
}
//CURRENT POSTER PALETTE:

//    CRGB red  = CRGB::Red ;
//    CRGB orange = CRGB::DarkOrange;
//    CRGB deeppink  = CRGB::DeepPink;
//    
//    currentPalette = CRGBPalette16(
//                                   red,  orange,  deeppink,  deeppink,
//                                   red,  orange,  deeppink,  deeppink,
//                                   red,  orange,  deeppink,  deeppink,
//                                   red,  orange,  deeppink,  deeppink );



// Additionl notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.
