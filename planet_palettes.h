/* ) . . o o 0 0 0 0 . Planet Palettes  ) . . o o 0 0 0 0 .



   Take a tour through the solar system
   with this pack of planetary
   colour schemes




*/




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




DEFINE_GRADIENT_PALETTE( planet_jupiter) {
  0,         140,   87,    20,     // mud   0
  40,        180,    134,    20 ,    //gravel 1
  42,         220,    140,   20 ,      // dirty orange (very thin) 2
  45,        224,   194,   20,    //tan_suit 3
  70,        205,   191,    40,      //sand 4
  73,       130,    127,     125,     // clouds or grey_clouds (very thin) 5
  78,       255,    106,     2,      // reddish_dust (medium thin) 6
 90,       250,    160,     13,    // dirty_orange (thicc) 7
 140,       228,   181,    20,     //sand (thin) 8
  160,       200,   87,     20,       //mud (thin) 9
   180,      223,   140,   20,      // tan_suit (mid thin) 10
  190,       255,   10,     0,      // red_dot (thin) 11
    194,      150,    100,   2,       // gravel  (thick) 13
  197,      137,    135,     120,     // clouds (thin) 12
  202,        202,  140,   20,        // tan suit 14
  255,      131,   87,    20         // mud (thin) 15

};



DEFINE_GRADIENT_PALETTE(planet_saturn) {
  0,         131,   87,    20,     // mud   0
  40,        166,    134,    20 ,    //gravel 1
  42,         207,    140,   20 ,      // dirty orange (very thin) 2
  45,        202,   194,   20,    //tan_suit 3
  70,        228,   214,    20,      //sand 4
  73,       233,    233,     221,     // clouds or grey_clouds (very thin) 5
  75,       245,    106,     2,      // reddish_dust (medium thin) 6
 80,       220,    160,     13,    // dirty_orange (thicc) 7
 120,       228,   214,    20,     //sand (thin) 8
  180,       131,   87,     20,       //mud (thin) 9
   190,      202,   194,   20,      // tan_suit (mid thin) 10
  192,       255,   50,     20,      // red_dot (thin) 11
  195,      233,    233,     221,     // clouds (thin) 12
  200,      166,    134,   2,       // gravel  (thick) 13
  235,        202,   194,   20,        // tan suit 14
  255,      131,   87,    20         // mud (thin) 15

};



DEFINE_GRADIENT_PALETTE( colour_tester) {
  0,        139,  75, 1,    /* at index 0, blue(0,0,0) */

  255,    139,  75, 15       /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};

// add a macro to DEFINE_HSV_GRADIENT_PALETTE

#define START_PALETTE planet_jupiter


/* Not controlable enough Shame
CRGBPalette16 planet_jupiter() {

  CRGB cloud  = CHSV( 0, 0, 255);
  CRGB grey_cloud = CHSV( 0, 0, 110);

  CRGB golden = CHSV(33, 204, 181);
  CRGB sand = CHSV( 38, 138, 227);
  CRGB tan_suit  = CHSV( 31, 99, 70);
  CRGB gravel = CHSV( 30, 43, 70);
  CRGB mud  = CHSV( 21, 115, 110);

  CRGB dirty_orange  = CHSV( 15, 74, 110);
  CRGB reddish_dust  = CHSV( 21, 189, 181);

  CRGB red_spot = CHSV( 0, 189, 181);

CRGBPalette16 output =  CRGBPalette16( mud,  dirty_orange,  gravel,  tan_suit,
                     cloud, sand, sand,  reddish_dust,
                     dirty_orange,  mud,  sand,  grey_cloud,
                     golden, sand, red_spot,  mud);
  
 return output;


}
*/
