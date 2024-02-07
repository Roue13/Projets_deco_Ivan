#include "Defs.h"

void setup() {
  btn.attachClick(Prochaine_animation);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LUMINOSITE);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {

  switch (animation) {
    case 0:  // All RED
      Full_fill_RGB(CRGB::Red);
      break;

    case 1:  // All BLUE
      Full_fill_RGB(CRGB::Blue);
      break;

    case 2:  // All GREEN
      Full_fill_RGB(CRGB::Green);
      break;

    case 3:  // All YELLOW
      Full_fill_RGB(CRGB::Yellow);
      break;

    case 4:  // All WHITE
      Full_fill_RGB(CRGB::White);
      break;

    case 5:  // Full Color Fading
      EVERY_N_MILLISECONDS(30) {
        hue++;
        Full_fill_HSV(hue);
      }
      break;

    case 6:  // Moving Rainbow
      EVERY_N_MILLISECONDS(30) {
        hue++;
        Rainbow_Fill(hue);
      }
      break;

    case 7:  // (Static Crochet + Tentacle) and (Changing Color Captain's + Hook)
      EVERY_N_MILLISECONDS(50)
      hue++;
      Captains_Fill(hue, 255);
      Hook_Fill(hue + 128, 255);
      Captains_Fill(0, 255);  // White
      Captains_Fill(0, 255);  // White
      break;
  }
  btn.tick();
}
