#include <FastLED.h>

#define LED_PIN1    5
#define LED_PIN2    6
#define LED_PIN3    9
#define LED_PIN4    10
#define NUM_PINS    4
#define NUM_LEDS    20
#define BRIGHTNESS  30
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define SPEED       50
CRGB leds[NUM_PINS][NUM_LEDS];
#define UPDATES_PER_SECOND 100
int i = 0;
int h = 0;
int x = 0;
void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds[0], NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds[1], NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(leds[2], NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(leds[3], NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}

void loop() { 
  //syncedLeftRightRainbow();
  //leftRightRainbowSequence();
  leftRightBounceRainbow();
}
void syncedLeftRightRainbow(){
  x=0;
  for (i = 0; i < NUM_LEDS; i++){
    if (h>254){
      h=0;
    }
    for (x = 0; x < NUM_PINS; x++){
      //CRGB g = leds[x][i].setHue(h);
      //g.setHue(h)
      leds[x][i].setHue(h);
      h++;
    }
    FastLED.show();
    delay(SPEED);
  }
  i = 0;
  delay(SPEED);
}
void leftRightRainbowSequence(){
    for (x = 0; x < NUM_PINS; x++){ //Array: runs rainbow L->R down each strip sequentially
      for (i = 0; i < NUM_LEDS; i++){
        if (h>254){
          h = 0;
        }
        leds[x][i].setHue(h);
        h++;
        FastLED.show();
        delay(SPEED);
      }
   i = 0;
   delay(SPEED);
   }
}
void leftRightBounceRainbow(){ // bounces a rainbow, all stringa are synced

    for (i = 0; i < NUM_LEDS; i++){ //cycles a rainbow L->R
    if (h>254){
      h=0;
    }
    for (x=0; x<NUM_PINS; x++){
    leds[x][i].setHue(h);
    h++; 
    }
    FastLED.show();
    delay(SPEED);
  }
  for (i = NUM_LEDS-1; i >= 0; i--){ //cycles a rainbow L->R then bounces R->L and so forth
    if (h>254){
      h=0;
    }
        for (x=0; x<NUM_PINS; x++){
    leds[x][i].setHue(h);
    h++; 
        }
    FastLED.show();
    delay(SPEED);
  }  
  i=0;
  delay(SPEED);
  
}
