#ifndef DEFS_H
#define DEFS_H

#include <Arduino.h>
#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS 10
#define DATA_PIN 3
#define BUTTON_PIN 5
#define LUMINOSITE 250  // (entre 0=min et 255=max)
#define MAX_ANIMATIONS 9
#define VITESSE_ANIMATION 10
#define PULSE_CYCLES 70

OneButton btn = OneButton(BUTTON_PIN, true, true);
CRGB leds[NUM_LEDS];


int animation = 0;
int progress = 0;
int direction = 0;
uint8_t hue = 0;
uint8_t previous_hue = 0;

void Prochaine_animation() {
  animation = (animation + 1) % MAX_ANIMATIONS;
  hue = random(0, 255);
  progress = 0;
  direction = 0;
}

void Full_fill_RGB(CRGB Color) {
  fill_solid(leds, NUM_LEDS, Color);
  FastLED.show();
}

void Full_fill_HSV(uint8_t Hue) {
  fill_solid(leds, NUM_LEDS, CHSV(Hue, 255, 255));
  FastLED.show();
}

void Rainbow_Fill(uint8_t Hue) {
  fill_rainbow(leds, NUM_LEDS, Hue, 255 / NUM_LEDS);
  FastLED.show();
}

void Bounce(CRGB Color = CRGB::White) {
  if (Color != CRGB::White) {  //  Default color, only one color
    if (direction == 0) leds[progress] = Color;
    else if (direction == 1) leds[NUM_LEDS - progress - 1] = Color;

    if (progress == (NUM_LEDS - 1)) {
      direction = (direction + 1) % 2;
      progress = (progress + 1) % (NUM_LEDS);
    }
    progress = (progress + 1) % (NUM_LEDS);
  }

  else {  //  Changes color slowly
    hue++;
    Color = CHSV(hue, 255, 255);
    if (direction == 0) leds[progress] = Color;
    else if (direction == 1) leds[NUM_LEDS - progress - 1] = Color;

    if (progress == (NUM_LEDS - 1)) {
      direction = (direction + 1) % 2;
      progress = (progress + 1) % (NUM_LEDS);
    }
    progress = (progress + 1) % (NUM_LEDS);
  }

  fadeToBlackBy(leds, NUM_LEDS, 50);
  FastLED.show();
}

void Pulse() {
  progress++;
  if (progress == PULSE_CYCLES) {
    Full_fill_HSV(hue);
    hue = previous_hue + random(50, 205);
    previous_hue = hue;
    Serial.println(hue);
    progress = 0;
  }
  fadeToBlackBy(leds, NUM_LEDS, 10);
  FastLED.show();
}

#endif DEFS_H