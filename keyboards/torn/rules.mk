<<<<<<< HEAD
# Build Options
#   change yes to no to disable
#   see info.json as well; rules.mk overrides rules.json
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
ENCODER_ENABLE = yes        # Enable rotary encoder
OLED_ENABLE = yes
WPM_ENABLE = yes
=======
>>>>>>> a1cb82286102bf4494ba856e2e8a348424929b34
CUSTOM_MATRIX = lite

SRC += matrix.c \
    bongocat.c \
    mcp23018.c \
    torn_encoder.c

I2C_DRIVER_REQUIRED = yes
