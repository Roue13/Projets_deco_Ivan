#ifndef DEFS_H
#define DEFS_H

#define DEBUG true

/* ---------- LIBRAIRIES ---------- */
#include <FastLED.h>
#include <OneButton.h>
#include <math.h>


/* ---------- CONSTANTES ---------- */
#define BTN_VIT_PIN 2
#define BTN_ANM_PIN 3
#define LED_PIN 7
#define LUM_POT_PIN A0

#define NUM_LEDS 22

#define LUM_SENSI 10  // Sensi de 0 � 255
#define MAX_ANIMATIONS 4
#define MAX_VITESSES 3


/* ---------- VARIABLES ---------- */
CRGB leds[NUM_LEDS];

OneButton btn_vit(BTN_VIT_PIN, true);  // Bouton animation
OneButton btn_anm(BTN_ANM_PIN, true);  // Bouton vitesse

unsigned long previousMillis = 0;

uint8_t luminosite = 200;
uint8_t teinte = 0;

uint8_t progression = 0;
uint8_t animation = 0;
uint8_t vitesse = 1;

#endif /* DEFS_H */