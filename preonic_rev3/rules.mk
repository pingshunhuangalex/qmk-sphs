SRC += muse.c

# Build Options
# change to "no" to disable the options, or define them in the Makefile in
# the appropriate keymap folder that will get included automatically
NKRO_ENABLE = yes       # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
MIDI_ENABLE = no        # MIDI controls
AUDIO_ENABLE = no       # Audio output
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend

LAYOUTS = ortho_5x12
