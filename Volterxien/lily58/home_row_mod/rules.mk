MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
AUDIO_ENABLE = no           # Audio output
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
SPACE_CADET_ENABLE = no 
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no 
RGBLIGHT_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
# OLED_ENABLE = no
RGB_MATRIX_ENABLE = no
LEADER_ENABLE = yes

CAPS_WORD_ENABLE = yes
BOTH_SHIFTS_TURNS_ON_CAPS_WORD = yes
WPM_ENABLE = yes
COMBO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
MUSIC_ENABLE = no
AUDIO_ENABLE = no
DEFERRED_EXEC_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        features/achordion.c
        #./lib/rgb_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
