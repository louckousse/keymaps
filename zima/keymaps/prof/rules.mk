
EXTRAFLAGS += -Wno-error=unused-variable -Wno-error=unused-function
EXTRAFLAGS += -Wno-unused-function -Wno-unused-variable
EXTRAFLAGS += -flto

LEADER_ENABLE = no        # Enable the Leader Key feature
WPM_ENABLE = yes
EXTRAKEY_ENABLE = no      # Audio control and System control
TAP_DANCE_ENABLE = no
HAPTIC_ENABLE = no
SRC += oled.c
