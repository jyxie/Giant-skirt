#include <Adafruit_NeoPixel.h>
#define PIN 5
 //It works! entire strip cycles through rainbow while black falls fromthetop
Adafruit_NeoPixel strip = Adafruit_NeoPixel(100, PIN, NEO_GRB + NEO_KHZ800);
int pixel = 0;
 
void setup() {
  strip.begin();
  strip.setBrightness(40);
  int i;
    /*for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i+1, Wheel(((i * 256 / strip.numPixels())) & 255));
    }*/
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
// strip.setPixelColor(pixel++,Wheel(pixel*256/strip.numPixels()));
  //strip.show();
  uint16_t i, j, k,h;
  k=0;
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
       strip.setPixelColor(i, Wheel(j));
       /*while(h>=0){
      strip.setPixelColor(h,0);
      }*/
      }
   h=k;  
  // while(h<26){ 
  while(h<51){
  strip.setPixelColor(h-1,0);
  //strip.setPixelColor(k+1,0);
  //strip.setPixelColor(k+4,0);
  //strip.setPixelColor(50-h,0);
  strip.setPixelColor(100-h,0);
  h--;
  delay(1);
  }
  k++;
  if(k>strip.numPixels()){
     k=0;
    }
  strip.show();
  //delay(50);
  delay(80);
  }
  delay(0);
}

 
 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
