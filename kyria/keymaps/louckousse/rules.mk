OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
LEADER_ENABLE = no        # Enable the Leader Key feature
MOUSEKEY_ENABLE = no
WPM_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no

SRC += oled.c
SRC += encoder.c

EXTRAFLAGS += -Wno-error=unused-variable -Wno-error=unused-function
EXTRAFLAGS += -Wno-unused-function -Wno-unused-variable
EXTRAFLAGS += -flto

