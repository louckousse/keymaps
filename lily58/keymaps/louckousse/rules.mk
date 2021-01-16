OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
LEADER_ENABLE = no        # Enable the Leader Key feature
MOUSEKEY_ENABLE = no
WPM_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no
EXTRAKEY_ENABLE = yes      # Audio control and System control

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
EXTRAFLAGS += -Wno-error=unused-variable -Wno-error=unused-function
EXTRAFLAGS += -Wno-unused-function -Wno-unused-variable
EXTRAFLAGS += -flto

SRC += oled.c
SRC += encoder.c
SRC += ./lib/logo_reader.c
