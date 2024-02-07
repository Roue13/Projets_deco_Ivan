#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Defs.h"

void Animation_1(void) {
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
}

void Animation_2(void) {
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
}

void Animation_3(void) {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
}

void Animation_4(void) {
  fill_solid(leds, NUM_LEDS, CHSV(teinte, 255, luminosite));
  FastLED.show();
}

void Animation_5(void) {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
}

#endif /* ANIMATIONS_H */