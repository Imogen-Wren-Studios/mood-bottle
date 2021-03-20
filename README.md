# moodBottle *(V1.0.0)*
#### Built and maintained by [Declan Heard](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Bar/Mood light designed to control WS2812B Addressable LEDs for a feature ornament.
* Slow to Medium colour blending to create an effect that is visually stimulating without being too distracting.
* Great for background light for a bar or nightclub.
* A modern take on an 80s lava lamp with a far wider range of colours
* Colour Palettes hand picked for a mix of high impact and low impact effects

___________________________________________________________________________________________________________

## Effects Modes

### colour_palettes

Colour palettes were designed around some of my favourite colour combinations. They replicate well known plasma effects,
but by ristricting palettes to two or three shades, it creates a more random overall feeling than a constantly cycling rainbow effect.
Don't worry though, for people who love the "RGB Rainbow" effect, several palettes are included which navigate the entire colour spectrum
as well as a procedurally generated random palette.

All palettes in colour_palette mode are selected randomly using a random number generator.


### planet_palettes

Planet palettes are designed to be more subtle colour effects, a tour of the major bodies of the Sol System.

This mode is triggered every 10 minutes, instead of randomly selecting palettes, our tour starts in a heliocentric orbit
around our star: Sol. Its bright yellow and orange, ocasionally pierced by a bright white light, aims to reflect 
the feeling of gazing upon The Sun in space, harsh and unforgiving. 

From here we travel to Mercury, its reddish browns, oranges and yellows a welcome break from the harsh light before this. 

Onto Venus, the Oranges get more orange, the yellows become a toxic sulphurous cloud, and some pastell white clouds 
start swirling around. The planets surface might kill you instantly, but it sure is pretty to look at from orbit.

Our next stop is our mother world: Earth. Here we are welcomed by the familure blues and turqoise of our home seas, the deep
and lucious greens of our rainforests, the dirty yellows of the sahara as seen from space and the white whisps of clouds over the sea.

We leave the comfort of home, and fly to a far less forgiving world, Mars: The Red Planet. Although this palette is far less red than
one might expect. It was based on a mix between our impressions of Mars, and photos taken by our army of robots on the red planets surface. 
Browns, dark yellows and just a touch of white to reflect the frozen CO2 of the polar caps.

(Other Emotive Descriptions Coming Soon)



___________________________________________________________________________________________________________

## Getting Started
### Software Requirements
* FastLED Library available @ [FastLED Library](https://github.com/FastLED/FastLED)
* autoDelay Library available from Pan Galactic Tech @ [autoDelay Library](https://github.com/PanGalacticTech/autoDelay_Library)

### Hardware Requirements
* Arduino compatable board:
**Arduino Uno/Nano or ESP32 reccommended
* WS2812B Addressable LEDs
* 100r Resistor between data LED_PIN and Data In (DI) on LED strip
* 1000uF capacitor reccomended between 5v & GND for LED strip power supply 


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
`#define LED_PIN 5`

Specify number of LEDs in WS2812B strip
`#define NUM_LEDS    8`

Define the maximum brightness for all effects values from 0 - 255 are valid.
(N.B. Changing this setting will effect the colour balance of some effects)

`#define BRIGHTNESS  255`

These settings may need changing depending on the LED strip used.
Consult manufacturer and/or FastLED documentation for valid settings

`#define LED_TYPE    WS2811` <br>
`#define COLOR_ORDER GRB`


Settings that control overall timing of animations

`#define UPDATES_PER_SECOND 30`<br>
`#define HUE_STEPS 5`       

(Other Variables Coming Soon)

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
