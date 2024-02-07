#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "Defs.h"

void print_debug(void) {
  Serial.print("Luminosite : ");
  Serial.print(luminosite);
  Serial.print("    Animation : ");
  Serial.print(animation);
  Serial.print("    Vitesse : ");
  Serial.println(vitesse);
}

bool every_n_mils(int intervalle) {
  unsigned long currentMillis = millis();
  
  if (DEBUG) {
    Serial.print("Intervalle temps : ");
    Serial.print(currentMillis - previousMillis);
  }

  if (currentMillis - previousMillis >= intervalle) {
    previousMillis = currentMillis;
    return true;
  } else return false;
}


void prochaine_animation(void) {
  animation = (animation + 1) % MAX_ANIMATIONS;
  teinte = 0;
  progression = 0;
}

void prochaine_vitesse(void) {
  vitesse = (vitesse % MAX_VITESSES) + 1;
  teinte = 0;
}

void update_luminosite(void) {
  int lecture = map(analogRead(LUM_POT_PIN), 0, 1023, 0, 255);
  if (abs(lecture - luminosite) > LUM_SENSI) {
    FastLED.setBrightness(lecture);
    luminosite = lecture;
  }
}

#endif /* FONCTIONS_H */