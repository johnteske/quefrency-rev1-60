#pragma once

#define USE_SERIAL
//#define USE_I2C

#ifdef AUDIO_ENABLE
#    define B7_AUDIO  // B7 (timer 1) exposed on Elite-C
#    define NO_MUSIC_MODE

#    define TEMPO_DEFAULT 100

// SEEGSON Rewire System Boot
// TODO rests do not seem to work
#    define SEEGSON Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C5)
#    define STARTUP_SONG SONG(SEEGSON)

#    define AUDIO_CLICKY
#    define AUDIO_CLICKY_FREQ_DEFAULT 70.0f
#endif

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLED_NUM
#    define RGBLED_NUM 8
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_SLEEP
#endif
