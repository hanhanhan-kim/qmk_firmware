# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# Processor frequency.
F_CPU = 8000000

# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Input clock frequency.
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build Options
SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
AUDIO_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
ENCODER_ENABLE = no	

# Build Options - Bluetooth
# BLUETOOTH_ENABLE = yes  	# Latest QMK currenntly does not have functional Bluetooth. For future Bluetooth builds, use ZMK, not QMK. 
BLUETOOTH = BluefruitLE 	# This part we need to define the correct Bluetooth chipset. 
# In info.json, set NKRO: false, because as of 2023/10/16, NKRO is not suupported on the nRF1822 Bluetooth chipset