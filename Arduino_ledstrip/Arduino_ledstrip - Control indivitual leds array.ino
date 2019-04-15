#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 60


CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[15] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[36] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[20] = CRGB(255, 200, 20);
  FastLED.show();
  delay(500);
  leds[41] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);
  leds[30] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
}
