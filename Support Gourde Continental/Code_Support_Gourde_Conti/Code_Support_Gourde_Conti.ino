#include <Arduino_BuiltIn.h>

#include "Defs.h"
#include "Fonctions.h"
#include "Animations.h"
#include "Arduino.h"

void setup() {
  if (DEBUG) Serial.begin(115200);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(luminosite);

  btn_anm.attachClick(prochaine_animation);
  btn_vit.attachClick(prochaine_vitesse);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_VIT_PIN, INPUT_PULLUP);
  pinMode(BTN_ANM_PIN, INPUT_PULLUP);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {
  if (DEBUG) print_debug();

  switch (animation) {
    case 0:  // Tout en rouge
      Animation_1();
      break;

    case 1:  // Tout en vert
      Animation_2();
      break;

    case 2:  // Tout en bleu
      Animation_3();
      break;

    case 3:  // Tout d'une couleur, qui évolue avec le temps
      if (every_n_mils(vitesse * vitesse * 10) == true) teinte = (teinte + 1) % 256;
      Animation_4();
      break;

    case 4:  // Arc en ciel qui se balade
      Animation_5();
      break;
  }
  update_luminosite();
  btn_vit.tick();
  btn_anm.tick();
}
