#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  30
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100
int h = 0;
int i;
void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
  // put your setup code here, to run once:
  
}

void loop() {
  //leftRightRainbow();
  leftRightBounceRainbow();
}

void leftRightRainbow(){
    for (i = 0; i < NUM_LEDS; i++){ //cycles a rainbow L->R
    if (h>254){
      h=0;
    }
    leds[i].setHue(h);
    h++; 
    FastLED.show();
    delay(30);
  }
  i=0;
  delay(30);
}
void leftRightBounceRainbow(){
    for (i = 0; i < NUM_LEDS; i++){ //cycles a rainbow L->R
    if (h>254){
      h=0;
    }
    leds[i].setHue(h);
    h++; 
    FastLED.show();
    delay(30);
  }
  for (i = NUM_LEDS-1; i >= 0; i--){ //cycles a rainbow L->R then bounces R->L and so forth
    if (h>254){
      h=0;
    }
    leds[i].setHue(h);
    h++; 
    FastLED.show();
    delay(30);
  }  
  i=0;
  delay(30);
}

