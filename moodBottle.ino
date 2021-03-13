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

#include "colour_palettes.h"
#include "planet_palettes.h"


CRGBPalette16 currentPalette;
TBlendType    currentBlending;


CRGBPalette16 nextPalette;
//TBlendType    currentBlending;


extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


// set up instance of palette
//CRGBPalette16 tropicalPalette;




#define NUM_FX 9

#define SOLAR_SYSTEM true        // When true it overwrites switching and only does solar system mode

#define PRINT_INDEX false

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
      outputPalette = the_moon;
      Serial.println("The Moon");
      break;
    case 4:
      outputPalette = planet_mars;
      Serial.println("Mars");
      break;
    case 5:
      outputPalette = planet_jupiter;
      Serial.println("Jupiter");
      break;
    case 6:
      outputPalette = planet_saturn;
      Serial.println("Saturn");
      break;
    case 7:
      outputPalette = planet_earth;
      Serial.println("Uranus");
      break;
    case 8:
      outputPalette = planet_earth;
      Serial.println("Neptune");
      break;
    case 9:
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

  fastled_setup();

  currentPalette = START_PALETTE;
  // currentPalette = select_palette(random(0, 5));


  currentBlending = LINEARBLEND;

  // nextPalette = select_palette(random(0, NUM_FX));

  nextPalette = START_PALETTE;

}






autoDelay shift_effect;











bool fadetoblack = false;
bool fadetocolour = false;
bool blackpause = false;

uint32_t transition_timer = 45;    // effect transitions are in seconds

// Cycles through banks of palettes based on program type
void switchPalette() {
  if (shift_effect.secondsDelay(transition_timer)) {
    Serial.println("Fading into New Palette");
    currentPalette = nextPalette;
    if (solar_system_mode or SOLAR_SYSTEM) {
      fadetoblack = true;     // triggers the apply_fade function
      nextPalette = select_planet();    // next palette now is not used because crossfading function is removed HOWEVER, we can now fade to black, then place nextPallet into currentPallet before the fade in,
      // making the crossover seamless
    } else {
      nextPalette = select_palette(random(0, NUM_FX));
    }
  }
}

autoDelay programDelay;

#define PROGRAM_DELAY 10   // Delay to switch progams in minuites

// Function to change program from colours to planets periodically (10 mins?)

void switchProgram() {
  if (programDelay.minutesDelay(PROGRAM_DELAY)) {
    if (solar_system_mode) {
      solar_system_mode = false;
    } else {
      solar_system_mode = true;
    }
  }

}


#define FADE_BLACK_BY 1

// Fades to black as an intermediary between 2 palettes
void black_crossfade() {
  fade_to_black();
  fade_to_palette();
}

void fade_to_black() {
  for (int i = 0; i < 255; i++) {
    fadeToBlackBy (leds, NUM_LEDS, FADE_BLACK_BY);
    Serial.print("Fading To Black By: ");
    Serial.println(i);
    FastLED.show();
    delay(2);
  }

}

void fade_to_palette() {

  FastLED.setBrightness( 0);

  for (int i = 0; i < BRIGHTNESS; i++) {
    apply_palette();
    FastLED.setBrightness(i);
    FastLED.show();
    delay(2);
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





  switchPalette();                // Switches colour palette periodically (actually only changes nextPalette, which is blended into currentPalette u


  if (solar_system_mode or SOLAR_SYSTEM) {
    // No blending between palettes, apply fadethrough used instead (although this also can be called for other palettes so is in main loop)
  } else {
    nblendPaletteTowardPalette(currentPalette, nextPalette, 12);    // slow blend between palettes
  }


  apply_palette();               //applies palette to LED buffer

  apply_fadethrough();               // Changes master brightness in response to fadethrough triggers

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}


#define FADE_THROUGH_DELAY 4    // delay time between brightness changes during crossfade through black effect (millis)
#define PAUSE_BLACK_DELAY 500    // delay time to pause at black between crossfade for cleaner scene change effect

autoDelay fadeBlack;

byte p = 0;    // Global variable used to fade out from max brightness


void apply_fadethrough() {

  if (fadetoblack) {
    if (fadeBlack.millisDelay(FADE_THROUGH_DELAY)) {
      if (BRIGHTNESS - p >= 0) {
        FastLED.setBrightness(BRIGHTNESS - p);
        p++;
      } else {
        fadetoblack = false;
        blackpause = true;
        currentPalette = nextPalette;              // Nextpalette has been preloaded with the new palette ready for after the fadeout, so we apply that now.
        p = 0;
      }
    }

  } else if (blackpause) {
    if (fadeBlack.millisDelay(PAUSE_BLACK_DELAY)) {
      blackpause = false;
      fadetocolour = true;
    }
  } else if (fadetocolour) {
    if (fadeBlack.millisDelay(FADE_THROUGH_DELAY)) {
      if (p <= BRIGHTNESS) {
        FastLED.setBrightness(p);
        p++;
      } else {
        fadetocolour = false;
        p = 0;
      }
    }
  }
}



// Fills led buffer from palette
void apply_palette() {

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  FillLEDsFromPaletteColors(startIndex);


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
  if (PRINT_INDEX) {
    Serial.print("Colour Index: [");
    Serial.print(colorIndex);
    Serial.println("]");
  }
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
