#pragma once

#define USE_SERIAL

#define SPLIT_USB_DETECT

#ifdef AUDIO_ENABLE
#    include "_audio.h"
#endif

#ifdef RGBLIGHT_ENABLE
#    include "_rgblight.h"
#endif
