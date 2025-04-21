# Build Options
#   change yes to no to disable
#   see info.json as well; rules.mk overrides rules.json
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
ENCODER_ENABLE = yes        # Enable rotary encoder
OLED_ENABLE = yes
WPM_ENABLE = yes
CUSTOM_MATRIX = lite

SRC += matrix.c \
    bongocat.c \
    mcp23018.c \
    torn_encoder.c

QUANTUM_LIB_SRC += i2c_master.c
