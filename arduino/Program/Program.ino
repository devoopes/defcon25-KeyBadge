#include <Adafruit_NeoPixel.h>

#define PIN 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN, NEO_RGB + NEO_KHZ800);

int waitTime = 10;

void setup() {
  strip.begin();
}

void loop() {
  fadeInAndOut(255, 20, 147 , waitTime); // Pink (red)
  fadeInAndOut(32, 178, 170, waitTime); // Teal (green)
  fadeInAndOut(148, 0, 211, waitTime); //  Dark Violet (blue)  
}

void fadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b=0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
     }
     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
     }
     strip.show();
     delay(wait);
  };
};
