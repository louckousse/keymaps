ENCODER_ENABLE = no
RGBLIGHT_ENABLE = no
LEADER_ENABLE = no
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no
TRACKBALL_ENABLE = yes
POINTING_DEVICE_ENABLE = yes

EXTRAFLAGS += -Wno-error=unused-variable -Wno-error=unused-function
EXTRAFLAGS += -Wno-unused-function -Wno-unused-variable
EXTRAFLAGS += -flto

SRC += oled.c
