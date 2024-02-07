#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS 120
#define DATA_PIN 8
#define BUTTON_PIN 6
#define LUMINOSITE 100  // (entre 0 et 255)
#define MAX_ANIMATIONS 6

const int Nb_Leds_Crochet = 43;
const int Nb_Leds_Hook = 30;
const int Nb_Leds_Tentacule = 11;
const int Nb_Leds_Captains = 36;

const int ID_Leds_Crochet[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
const int ID_Leds_Hook[] = { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
const int ID_Leds_Tentacule[] = { 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 };
const int ID_Leds_Captains[] = { 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104 };

OneButton btn = OneButton(BUTTON_PIN, true, true);
CRGB leds[NUM_LEDS];

int animation = 0;
uint8_t hue = 0;

void Prochaine_animation() {
  animation = (animation + 1) % MAX_ANIMATIONS;
  hue = 0;
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

void Captains_Fill(uint8_t Hue, uint8_t Sat) {
  for (int i = 0; i < Nb_Leds_Captains; i++) {
    leds[ID_Leds_Captains[i]] = CHSV(Hue, Sat, 255);
  }
  FastLED.show();
}

void Hook_Fill(uint8_t Hue, uint8_t Sat) {
  for (int i = 0; i < Nb_Leds_Hook; i++) {
    leds[ID_Leds_Hook[i]] = CHSV(Hue, Sat, 255);
  }
  FastLED.show();
}

void Crochet_Fill(uint8_t Hue, uint8_t Sat) {
  for (int i = 0; i < Nb_Leds_Crochet; i++) {
    leds[ID_Leds_Crochet[i]] = CHSV(Hue, Sat, 255);
  }
  FastLED.show();
}

void Tentacule_Fill(uint8_t Hue, uint8_t Sat) {
  for (int i = 0; i < Nb_Leds_Tentacule; i++) {
    leds[ID_Leds_Tentacule[i]] = CHSV(Hue, Sat, 255);
  }
  FastLED.show();
}

void Wave_Captains_GD() {
  for (int i = 0; i < (Nb_Leds_Captains / 2); i++) {
    leds[ID_Leds_Captains[i]] = CRGB::Red;
    leds[ID_Leds_Captains[Nb_Leds_Captains - 1 - i]] = CRGB::Red;
  }
}

void Wave_Captains_DG() {
  for (int i = (Nb_Leds_Captains / 2); i > 0; i--) {
    leds[ID_Leds_Captains[(Nb_Leds_Captains / 2) - i]] = CRGB::Red;
    leds[ID_Leds_Captains[i]] = CRGB::Red;
  }
}

void Wave_Hook_GD() {
  for (int i = 0; i < 10; i++) {
    leds[ID_Leds_Hook[18 + i]] = CRGB::Red;
    if ((i >= 1) && (i < 9)) leds[ID_Leds_Hook[17 - i]] = CRGB::Red;
    if (i >= 1) leds[ID_Leds_Hook[i]] = CRGB::Red;
  }
}

void Wave_Hook_DG() {
  for (int i = 0; i < 10; i++) {
    leds[ID_Leds_Hook[Nb_Leds_Hook - 1 - i]] = CRGB::Red;
    if ((i>0) && (i<9)) leds[ID_Leds_Hook[9 + i]] = CRGB::Red;
    if (i < 9) leds[ID_Leds_Hook[8 - i]] = CRGB::Red;
  }
}
