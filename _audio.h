#define B7_AUDIO  // B7 (timer 1) exposed on Elite-C
#define NO_MUSIC_MODE

// TODO timing issue https://github.com/qmk/qmk_firmware/issues/8825
#undef TEMPO_DEFAULT
#define TEMPO_DEFAULT 255

// SEEGSON Rewire System Boot
#define SEEGSON Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C4), Q__NOTE(_REST), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_REST), Q__NOTE(_C5)

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 70.0f
