# MCU name
MCU = atmega32u4
# Bootloader selection
#   Pro Micro    caterina
BOOTLOADER = caterina
SPLIT_KEYBOARD = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

# Build Options
# BOOTMAGIC_ENABLE  = yes	# Virtual DIP switch configuration
# MOUSEKEY_ENABLE  = no	# Mouse keys
# EXTRAKEY_ENABLE  = yes	# Audio control and System control
# CONSOLE_ENABLE  = yes	# Console for debug
# COMMAND_ENABLE  = yes    # Commands for debug and configuration
# SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
# NKRO_ENABLE  = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE  = no  # Custom backlighting code is used, so this should not be enabled
# AUDIO_ENABLE  = no # This can be enabled if a speaker is connected to the expansion port. Not compatible with RGBLIGHT below
# RGBLIGHT_ENABLE  = no # This can be enabled if a ws2812 strip is connected to the expansion port.
OLED_DRIVER_ENABLE = no

# LAYOUTS = ortho_50tpuupttuuiitisn-nyyun