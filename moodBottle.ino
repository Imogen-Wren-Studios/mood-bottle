#include <FastLED.h>

#include <autoDelay.h>



#define LED_PIN     5
#define NUM_LEDS    9
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGBArray <NUM_LEDS> leds;

#define UPDATES_PER_SECOND 30
#define HUE_STEPS 5                // Number of steps to advance through palette between each for loop. Origionally 3

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


CRGBPalette16 nextPalette;
//TBlendType    currentBlending;


extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


// set up instance of palette
//CRGBPalette16 tropicalPalette;




DEFINE_GRADIENT_PALETTE( tropicalPalette ) {
  0,      255,  230,  0,    /* at index 0, yellow(0,0,0) */
  50,     255,  200,  0,    /* at index 0, orange(0,0,0) */
  100,      0,  255, 255,    /* at index 192, teal(255,0,0) */
  200,      0,  255, 100, /* at index 255, blue(255,255,255) */
  255,    255,  190,  0    /* at index 0, yellow(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( raggaPalette ) {
  0,      255,  255,  0,    /* at index 0, yellow(0,0,0) */
  100,     100,  255,  0,    /* at index 0, greenyellow(0,0,0) */
  150,      0,  255, 0,    /* at index 192, green(255,0,0) */
  200,     255,  0, 0, /* at index 255, red(255,255,255) */
  255,    255,  255,  0    /* at index 0, yellow(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( transPalette ) {
  0,      50,  230,  255,    /* at index 0, Blue(0,0,0) */
  50,     255,  50,  50,    /* at index 0, Pink(0,0,0) */
  125,      255,  255, 255,    /* at index 192, White(255,0,0) */
  200,     255,  50, 50, /* at index 255, Pink(255,255,255) */
  255,    50,  190,  255   /* at index 0, Blue(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( biPalette ) {
  0,        0,  255,  255,    /* at index 0, teal(0,0,0) */
  50,       0,  0,    255,    /* at index 0, blue(0,0,0) */
  190,    255,  0,    255, /* at index 255, purple(255,255,255) */
  255,    255,  0,    100   /* at index 0, deep purple(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( orange_white ) {
  0,        255,  200,  0,    /* at index 0, orange(0,0,0) */
  50,       255,  40, 0,    /* at index 0, orange(0,0,0) */
  235,     255,  100,  0,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    255,  50,    0   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( all_blue ) {
  0,        0,  255, 255,    /* at index 0, orange(0,0,0) */
  50,       0,  0, 255,    /* at index 0, orange(0,0,0) */
  235,     0,  255,  255,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    0,  40,   255   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( green_white ) {
  0,        0,  255, 0,    /* at index 0, orange(0,0,0) */
  50,       100,  255, 0,    /* at index 0, orange(0,0,0) */
  235,     0,  255,  0,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    120,  255,   0   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( planet_earth) {
  0,        0,  0, 255,    /* at index 0, blue(0,0,0) */
  5,        0,  200, 255,    /* at index 0, blue(0,0,0) */
  10,       255,  255, 255,    /* at index 0, blue(0,0,0) */
  15,        0,  0, 255,    /* at index 0, blue(0,0,0) */
  100,        0,  100, 255,    /* at index 0, blue(0,0,0) */
  120,       0,  255, 0,    /* at index 0, green(0,0,0) */
  140,       100,  255, 0,    /* at index 0, green(0,0,0) */
  150,     0,  255,  150,    /* at index 0, blue(0,0,0) */
  200,     0,  255,  0,    /* at index 0, green(0,0,0) */
  220,     150,  255,  0,    /* at index 0, green(0,0,0) */
  235,        139,  75, 1,    /* at index 0, desertbrown(0,0,0) */
  240,    139,  75, 15,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    255,  200,    0, /* at index 255, desertbright(255,255,255) */
  255,    0,  100,   255   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( planet_mercury) {
  0,        255, 190, 0,    /* at index 0, blue(0,0,0) */
  5,        255,  200, 0,    /* at index 0, blue(0,0,0) */
  10,       255,  20, 0,    /* at index 0, blue(0,0,0) */
  15,       255,  100, 0,    /* at index 0, blue(0,0,0) */
  100,        255,  0, 0,    /* at index 0, blue(0,0,0) */
  120,       255,  190, 5,    /* at index 0, green(0,0,0) */
  140,       150,  100, 0,    /* at index 0, green(0,0,0) */
  150,     255,  190,  0,    /* at index 0, blue(0,0,0) */
  200,     250,  20,  0,    /* at index 0, green(0,0,0) */
  220,     150,  50,  0,    /* at index 0, green(0,0,0) */
  235,      139,  75, 1,    /* at index 0, desertbrown(0,0,0) */
  240,        0,  0, 0,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    145,  60,    0, /* at index 255, desertbright(255,255,255) */
  255,    50,  50,   0   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( planet_venus) {
  0,        190, 190, 170,    /* at index 0, blue(0,0,0) */
  5,        230,  200, 100,    /* at index 0, blue(0,0,0) */
  10,       230,  200, 20,    /* at index 0, blue(0,0,0) */
  15,       150,  120, 90,    /* at index 0, blue(0,0,0) */
  100,        70,  50, 40,    /* at index 0, blue(0,0,0) */
  120,       220,  190, 150,    /* at index 0, green(0,0,0) */
  140,       150,  100, 50,    /* at index 0, green(0,0,0) */
  150,     200,  190,  40,    /* at index 0, blue(0,0,0) */
  200,     250, 70,  0,    /* at index 0, green(0,0,0) */
  210,     150,  100,  0,    /* at index 0, green(0,0,0) */
  235,      140,  65, 1,    /* at index 0, desertbrown(0,0,0) */
  240,        0,  0, 0,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    145,  120,    30, /* at index 255, desertbright(255,255,255) */
  255,    60,  50,   50   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};

// Would prefer an HSV way of specifying this.
DEFINE_GRADIENT_PALETTE( planet_mars) {
  0,        255, 140, 0,    /* at index 0, blue(0,0,0) */
  8,        240,  20, 0,    /* at index 0, blue(0,0,0) */
  10,       200,  170, 100,    /* at index 0, blue(0,0,0) */
  13,       200,  100, 0,    /* at index 0, blue(0,0,0) */
  100,        190,  50, 0,    /* at index 0, blue(0,0,0) */
  120,       240,  50, 0,    /* at index 0, green(0,0,0) */
  140,      190,  64, 0,    /* at index 0, green(0,0,0) */
  150,     230,  30,  0,    /* at index 0, blue(0,0,0) */
  200,     255, 23,  0,    /* at index 0, green(0,0,0) */
  210,     100,  100,  0,    /* at index 0, green(0,0,0) */
  235,      200,  65, 1,    /* at index 0, desertbrown(0,0,0) */
  240,        0,  0, 0,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    145,  40,    0, /* at index 255, desertbright(255,255,255) */
  255,    120,  60,   0   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( colour_tester) {
  0,        139,  75, 1,    /* at index 0, blue(0,0,0) */

  255,    139,  75, 15       /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};

// add a macro to DEFINE_HSV_GRADIENT_PALETTE

#define START_PALETTE planet_mars

#define NUM_FX 9

#define SOLAR_SYSTEM true        // When true it overwrites switching and only does solar system mode

bool solar_system_mode = true;

CRGBPalette16 select_palette(byte number) {

  CRGBPalette16 outputPalette;


  switch (number) {
    case 0:
      outputPalette = tropicalPalette;
      Serial.println("Tropical");
      break;
    case 1:
      outputPalette = raggaPalette;
      Serial.println("Ragga");
      break;
    case 2:
      outputPalette = transPalette;
      Serial.println("Trans");
      break;
    case 3:
      outputPalette = biPalette;
      Serial.println("Bi");
      break;
    case 4:
      outputPalette = orange_white;
      Serial.println("Orange/White");
      break;
    case 5:
      outputPalette = all_blue;
      Serial.println("All Blue");
      break;
    case 6:
      outputPalette = green_white;
      Serial.println("Green/White");
      break;
    case 7:
      outputPalette = planet_earth;
      Serial.println("Planet Earth");
      break;
    default:
      Serial.println("Random");
      for ( int i = 0; i < 16; i++) {
        outputPalette[i] = CHSV( random8(), 255, random8());
      }
      break;
  }
  //return green_white;
  return outputPalette;
}


byte current_planet = 0;

CRGBPalette16 select_planet() {

  CRGBPalette16 outputPalette;


  switch (current_planet) {
    case 0:
      outputPalette = planet_mercury;
      Serial.println("Mercury");
      break;
    case 1:
      outputPalette = planet_venus;
      Serial.println("Venus");
      break;
    case 2:
      outputPalette = planet_earth;
      Serial.println("Earth");
      break;
    case 3:
      outputPalette = planet_mars;
      Serial.println("Mars");
      break;
    case 4:
      outputPalette = planet_earth;
      Serial.println("Jupiter");
      break;
    case 5:
      outputPalette = planet_earth;
      Serial.println("Saturn");
      break;
    case 6:
      outputPalette = planet_earth;
      Serial.println("Uranus");
      break;
    case 7:
      outputPalette = planet_earth;
      Serial.println("Neptune");
      break;
    case 8:
      outputPalette = planet_earth;
      Serial.println("Pluto");
      break;

    default:
      Serial.println("Random");
      for ( int i = 0; i < 16; i++) {
        outputPalette[i] = CHSV( random8(), 255, random8());
      }
      break;
  }
  //return green_white;
  current_planet++;

  if (current_planet >= 9) {
    current_planet = 0;
  }
  return outputPalette;
}







char debugPrint[42];


void setup() {
  Serial.begin(115200);
  Serial.println("Gathering Spectrum...");
  delay( 1000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.println("...Processing Light Threads...");
  FastLED.setBrightness(  BRIGHTNESS );

  randomSeed(analogRead(0));   // psudo random number generator for randomness & chaos

  leds(0, 9) = CHSV(255, 255, 0);

  Serial.println("               Weaving Colours...  \n     ...Selecting Pigments\n");
  delay(500);
  Serial.println("Chroma Paintbrush Initialised:  Luminescence Matrix Applied.\n Starting Visual Light Imbument\n ");
  FastLED.show();



  currentPalette = START_PALETTE;
  // currentPalette = select_palette(random(0, 5));


  currentBlending = LINEARBLEND;

  // nextPalette = select_palette(random(0, NUM_FX));

  nextPalette = START_PALETTE;

}






autoDelay shift_effect;






uint32_t transition_timer = 45;    // effect transitions are in seconds



// Cycles through banks of palettes based on program type

void switchPalette() {
  if (shift_effect.secondsDelay(transition_timer)) {
    Serial.println("Fading into New Palette");
    currentPalette = nextPalette;
    
    if (SOLAR_SYSTEM) {
      nextPalette = select_planet();
    } else if (solar_system_mode){
       nextPalette = select_planet();
    } else {
      nextPalette = select_palette(random(0, NUM_FX));
    }
  }
}

autoDelay programDelay;

#define PROGRAM_DELAY 10   // Delay to switch progams in minuites

// Function to change program from colours to planets periodically (10 mins?)

void switchProgram(){
  if (programDelay.minutesDelay(PROGRAM_DELAY)){
  if (solar_system_mode){
   solar_system_mode = false;
  } else {
    solar_sytem_mode = true;
  }
  }
  
}






/*
    Change in paradigm

      - Program is always "Transitioning" from one to another, it seems to take less than 1min to transition
      so each effect will cycle for at least 2 mins


*/

void loop() {
  randomise_led_directions();    // Changes the direction the LEDs are painted in
  //  randomise_colour_direction();   // < Dont like the effect this has meant to randomise the direction of the colour wheel, but causes jumps and skips


  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */




  switchPalette();                // Switches colour palette periodically (actually only changes nextPalette, which is blended into currentPalette u



  nblendPaletteTowardPalette(currentPalette, nextPalette, 12);    // blends next palette into currentPalette


  FillLEDsFromPaletteColors(startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}





// Elements to change things at different times for randomness

autoDelay hueShiftDelay;

int hue_steps = 3;
uint32_t hue_shift_timing = 5000;


void randomise_colour_direction() {
  if (hueShiftDelay.millisDelay(hue_shift_timing)) {
    hue_steps = random(-10, 10);
    //  sprintf(debugPrint, "hue_steps: [%i]", hue_steps);
    //  Serial.println(debugPrint);
  }

}



autoDelay directionDelay;   // Controls the delay between rolling dice on a direction change

uint32_t direction_timing = 5000;

bool ledDirection = true;         // Sets the LEDs to update in a positive direction if true, or reverse direction if false


void randomise_led_directions() {
  if (directionDelay.millisDelay(direction_timing)) {    // if delay time is up,
    byte diceRoll = random(0, 5);                               // Roll the dice
    Serial.print("Roll Dice: [");
    Serial.print(diceRoll);
    Serial.println("]");
    if (diceRoll < 1) {                                     // if less than 2, //do nothing
      //   Serial.println("Dice Roll Failed, Direction Unchanged");
    } else {
      if (ledDirection) {
        ledDirection = false;
        //  Serial.println("LED Direction Backwards");
      } else {
        ledDirection = true;                                 // Else Change the directions
        //  Serial.println("LED Direction Forwards.");
      }

    }
    // Function here to randomise direction_timing
    direction_timing = random(500, 15000);                       // Randomise changing direction again from between 0.5s to 10s
    //  sprintf(debugPrint, "Direction Timing: [%u]", direction_timing);
    //Serial.println(debugPrint);

    // Serial.println(debugPrint);
  }
}






// Utilities

void FillLEDsFromPaletteColors( uint8_t colorIndex) {

  if (ledDirection) {
    for ( int i = 0; i < NUM_LEDS; i++) {
      leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      colorIndex += hue_steps;
    }
  } else {                                                                                              // Same for loop as before but runs in reverse order
    for ( int i = NUM_LEDS; i >= 0; i--) {
      leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
      colorIndex += hue_steps;

    }
  }
  Serial.print("Colour Index: [");
  Serial.print(colorIndex);
  Serial.println("]");

}



// nblendPaletteTowardPalette:
//               Alter one palette by making it slightly more like
//               a 'target palette', used for palette cross-fades.
//
//               It does this by comparing each of the R, G, and B channels
//               of each entry in the current palette to the corresponding
//               entry in the target palette and making small adjustments:
//                 If the Red channel is too low, it will be increased.
//                 If the Red channel is too high, it will be slightly reduced.
//                 ... and likewise for Green and Blue channels.
//
//               Additionally, there are two significant visual improvements
//               to this algorithm implemented here.  First is this:
//                 When increasing a channel, it is stepped up by ONE.
//                 When decreasing a channel, it is stepped down by TWO.
//               Due to the way the eye perceives light, and the way colors
//               are represented in RGB, this produces a more uniform apparent
//               brightness when cross-fading between most palette colors.
//
//               The second visual tweak is limiting the number of changes
//               that will be made to the palette at once.  If all the palette
//               entries are changed at once, it can give a muddled appearance.
//               However, if only a few palette entries are changed at once,
//               you get a visually smoother transition: in the middle of the
//               cross-fade your current palette will actually contain some
//               colors from the old palette, a few blended colors, and some
//               colors from the new palette.
//               The maximum number of possible palette changes per call
//               is 48 (sixteen color entries time three channels each).
//               The default 'maximim number of changes' here is 12, meaning
//               that only approximately a quarter of the palette entries
//               will be changed per call.
/*
                  CRGBPalette16& currentPalette,
                                CRGBPalette16& targetPalette,
                                uint8_t maxChanges=24);

*/
//nblendPaletteTowardPalette(currentPalette, nextPalette, 24);



void solid_colour_hsv(byte hue, byte sat, byte brightness) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, sat, brightness);
  }

}

void solid_colour_rgb(byte r, byte g, byte b) {
  leds(0, NUM_LEDS) = CRGB(r, g, b);
}






// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.

void ChangePalettePeriodically() {
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    if ( secondHand ==  0)  {
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 10)  {
      currentPalette = RainbowStripeColors_p;
      currentBlending = NOBLEND;
    }
    if ( secondHand == 15)  {
      currentPalette = RainbowStripeColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 20)  {
      SetupPurpleAndGreenPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 25)  {
      SetupTotallyRandomPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 30)  {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = NOBLEND;
    }
    if ( secondHand == 35)  {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 40)  {
      currentPalette = CloudColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 45)  {
      currentPalette = PartyColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 50)  {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = NOBLEND;
    }
    if ( secondHand == 55)  {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = LINEARBLEND;
    }
  }
}






// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette() {
  for ( int i = 0; i < 16; i++) {
    currentPalette[i] = CHSV( random8(), 255, 255);
  }
}






// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.
void SetupBlackAndWhiteStripedPalette() {
  // 'black out' all 16 palette entries...
  fill_solid( currentPalette, 16, CRGB::Black);
  // and set every fourth one to white.
  currentPalette[0] = CRGB::White;
  currentPalette[4] = CRGB::White;
  currentPalette[8] = CRGB::White;
  currentPalette[12] = CRGB::White;

}





// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette() {
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;

  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     purple, purple, black,  black,
                     green,  green,  black,  black,
                     purple, purple, black,  black );
}







// This example shows how to set up a static color palette
// which is stored in PROGMEM (flash), which is almost always more
// plentiful than RAM.  A static PROGMEM palette like this
// takes up 64 bytes of flash.
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
  CRGB::Red,
  CRGB::Gray, // 'white' is too bright compared to red and blue
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Red,
  CRGB::Gray,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Blue,
  CRGB::Black,
  CRGB::Black
};






// Additional notes on FastLED compact palettes:
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
