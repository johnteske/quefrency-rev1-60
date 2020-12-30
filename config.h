#pragma once

#define USE_SERIAL
//#define USE_I2C

#ifdef AUDIO_ENABLE
#    define B7_AUDIO  // B7 (timer 1) exposed on Elite-C
#    define NO_MUSIC_MODE

// TODO timing issue https://github.com/qmk/qmk_firmware/issues/8825
#    undef TEMPO_DEFAULT
#    define TEMPO_DEFAULT 255

// SEEGSON Rewire System Boot
#    define SEEGSON Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C5)

#    define AUDIO_CLICKY
#    define AUDIO_CLICKY_FREQ_DEFAULT 70.0f
#endif

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLED_NUM
#    define RGBLED_NUM 8
#    define RGBLIGHT_LED_MAP \
        { 7, 6, 5, 4, 3, 2, 1, 0 }
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LIMIT_VAL 32
#    define RGBLIGHT_SLEEP  // turn off lighting when host sleeps
#endif
