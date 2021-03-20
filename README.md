# moodBottle *(V1.0.0)*
#### Built and maintained by [Declan Heard](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Bar/Mood light designed to control WS2812B Addressable LEDs for a feature ornament.
* Slow to Medium colour blending to create an effect that is visually stimulating without being too distracting.
* Great for background light for a bar or nightclub.
* A modern take on an 80s lava lamp with a far wider range and mixes of colours
* Colour Palettes hand picked for a mix of high impact and low impact effects
  * 2 Major modes: colour_palettes: High Impact Palettes, and planet_palettes: Low impact mode
* Optimised for short WS2821B LED strings. All effects designed and optimized for just 8 LEDs! (But use as many as you wish)

___________________________________________________________________________________________________________

## Effects Modes

### colour_palettes

<p>Colour palettes were designed around some of my favourite colour combinations. They replicate well known plasma effects,
but by ristricting palettes to two or three shades, it creates a more random overall feeling than a constantly cycling rainbow effect.
Don't worry though, for people who love the "RGB Rainbow" effect, several palettes are included which navigate the entire colour spectrum
as well as a procedurally generated random palette. </p>

<p>All palettes in colour_palette mode are selected randomly using a random number generator.</p>


### planet_palettes

<p>Planet palettes are designed to be more subtle colour effects, based on a virtual tour of the major bodies of the Sol System.</p> <br>

<p>This mode is triggered every 10 minutes, instead of randomly selecting palettes, our voyage starts in a heliocentric orbit
around our star: **Sol** . Its bright yellow and orange, ocasionally pierced by a bright white light, aims to reflect 
the feeling of gazing upon The Sun in space, harsh and unforgiving.</p> <br>

<p>From here we travel to **Mercury** , its reddish browns, oranges and yellows reflect its surface hot enough to melt tin, but it still 
makes a welcome break from the harsh light before this.</p> <br>

<p>On to **Venus** , the Oranges get more orange, the yellows become a toxic sulphurous cloud, and some pastel white clouds 
start swirling. The planets surface might kill you instantly, but it sure is pretty to look at from orbit.</p><br>

<p>Our next stop is our mother world: **Earth** . Here we are welcomed by the familiar blues and turquoise of our home seas, the deep
and lucious greens of our rainforests, the dirty yellows of the sahara as seen from space, and the white whisps of clouds over the sea. 
Watch out for a brief fly-past **The Moon** on our way out towards the outer planets.</p><br>

<p>We leave the comfort of home, and fly to a far less forgiving world, **Mars** : The Red Planet. Although this palette is far less red than
one might expect. It was based on a mix between our impressions of Mars from a distance, and photos taken by our army of robots on the
red planet's surface and in orbit. Browns, dark yellows and just a touch of white to reflect the frozen CO2 of the polar caps.</p><br>

<p>After our brief stops at each of the inner planets of the solar system, we pass the first of the gas giants, **Jupiter** . Its swirling white,
orange, and yellow storms are peirced by a short flash of deep red, the biggest storm of the solar system and Jupiters most defining feature.</p><br>

<p>Following in the footsteps of Voyager 2, we continue our tour of all the gas-giants. We arrive at **Saturn** , the brighter oranges of Jupiter
are replaced with more subtle yellows and browns. Unlike Cassini, our journey does not end in the atmospheric clouds of Saturn, but on we continue...</p><br>
<br>
To the blue methane worlds of **Neptune** & **Uranius** , both morphing between turquoise and deep blues, with the occasional white clouds and storms.</p> <br>

<p>Finally we arrive at **Pluto** , this palette is based upon the false-colour images of Pluto's icy surface generated from images taken by the New Horizons
spacecraft. Different types of ice are highlighted in whites, blues, reds and greys. <br>

<p>With our Voyage complete, we fade to black, and the program reverts to colour_palettes mode.</p><br><br>


___________________________________________________________________________________________________________

## Getting Started
### Software Requirements
* FastLED Library available @ [FastLED Library](https://github.com/FastLED/FastLED)
* autoDelay Library available from Pan Galactic Tech @ [autoDelay Library](https://github.com/PanGalacticTech/autoDelay_Library)

### Hardware Requirements
* Arduino compatable board:
  * Arduino Uno/Nano or ESP32 reccommended
* WS2812B Addressable LEDs
* 100r Resistor between data LED_PIN and Data In (DI) on LED strip
* 1000uF capacitor reccomended between 5v & GND for LED strip power supply
* WARNING: Each WS2812B LED can draw **up to** 60 mA.
   * Calculate total current draw for your strip and use a suitable power supply. 


### Deployment
1. Clone or Download folder into Arduino IDE projects folder
2. Extract files from zipped folder if required.
3. Open moodBottle.ino in Arduino IDE.
4. Upload sketch to compatable Arduino board (Tested on Arduino Uno & Arduino Nano)

___________________________________________________________________________________________________________

## User Options:

Program contains some settings that can be easily edited to change the program flow. Detailed below.

### In moodBottle.ini File

Select the data pin for WS2812B
`#define LED_PIN 5`<br><br>

Specify number of LEDs in WS2812B strip
`#define NUM_LEDS    8`<br><br>

Define the maximum brightness for all effects values from 0 - 255 are valid.
(N.B. Changing this setting will effect the colour balance of some effects)

`#define BRIGHTNESS  255`<br><br>

These settings may need changing depending on the LED strip used.
Consult manufacturer and/or FastLED documentation for valid settings.

`#define LED_TYPE    WS2811` <br>
`#define COLOR_ORDER GRB`<br><br>


#### Settings that control overall timing of animations:

Set framerate, Reccomended between 25 & 60 fps.

`#define UPDATES_PER_SECOND 30`<br>

Define the number of steps each palette cycles through the hues between each LED in the strip.<br>
We feel that 5 is a good balance between an interesting effect that doesn't feel too manic. <br>.
`#define HUE_STEPS 5`   <br>         


When true it overwrites switching, only outputs solar system mode<br>

`#define SOLAR_SYSTEM false      `

If Set false, colours are painted in a single direction only. If true, direction changes at random periods.<br>

`#define RANDOMISE_DIRECTION true `<br><br>

Pick any named Palette as the start palette on system power up or reset. <br>
`#define START_PALETTE white_light   `<br><br>

Alternative option for picking a totally random colour_palette for start palette. <br>
`//#define START_PALETTE select_palette(random(0, NUM_FX));  ` <br><br>

Debug Variables. Easily switch debug outputs on and off.

`#define PRINT_INDEX false`<br>
`#define DEBUG_DELAY false`<br>
`#define DEBUG_DELAY_TIME 300`<br><br>

Fade to black constants. Used for planet_palettes.

`#define FADE_THROUGH_DELAY 1   // delay time between brightness changes during crossfade through black effect (millis)` <br>
`#define PAUSE_BLACK_DELAY 100    // delay time to pause at black between crossfade for cleaner scene change effect`<br><br>

Define the number of minutes between triggering planet_palette mode.

`#define PROGRAM_DELAY 10 `<br>



<br>
________________________________________________________________________________________________________


<br>
<br>

___________________________________________________________________________________________________________
___________________________________________________________________________________________________________

### Limitations:



<br>

### Known Issues V1.0.0
  - Please report any bugs or issues found.

<br>

### Features to be Added 

<br>
<br>

## About
### Built With
* [Arduino IDE](https://www.arduino.cc/) - Default IDE
* [FastLED Library]( ) -


### Author
#### Declan Heard
* [LinkedIn](https://www.linkedin.com/in/declan-heard-91103b58/)
* Email: [Personal](mailto:dec.h38@gmail.com "dec.h38@gmail.com") | [Company](mailto:PanGalacticTech@gmail.com "PanGalacticTech@gmail.com")
* [Github Profile](https://github.com/PanGalacticTech)
