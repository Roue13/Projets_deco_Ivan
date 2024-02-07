#include "Defs.h"

void setup() {
  Serial.begin(9600);
  btn.attachClick(Prochaine_animation);
  randomSeed(analogRead(0));

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
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
      EVERY_N_MILLISECONDS(VITESSE_ANIMATION *2) {
        hue++;
        Full_fill_HSV(hue);
      }
      break;
    case 6:  // Moving Rainbow
      EVERY_N_MILLISECONDS(VITESSE_ANIMATION) {
        hue++;
        Rainbow_Fill(hue);
      }
      break;
    case 7:  // Bounce on borders
      EVERY_N_MILLISECONDS(VITESSE_ANIMATION * 5)
      //Bounce(CRGB::Blue);   // Comment here for selected color only
      Bounce();  //              Comment here for slow color fading
      break;
    case 8:  // Pulse
      EVERY_N_MILLISECONDS(VITESSE_ANIMATION*3)
      Pulse();
      break;
  }
  btn.tick();
}
