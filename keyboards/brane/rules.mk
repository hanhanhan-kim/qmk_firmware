# MCU name
MCU = atmega32u4

# Build Options
#   comment out to disable the options.
#
# EXTRAFLAGS+=-flto
LTO_ENABLE = yes
BACKLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
RGBLIGHT_ENABLE = yes    # RGB lighting
ENCODER_ENABLE = no

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
