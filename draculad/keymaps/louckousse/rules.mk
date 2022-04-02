# only uncomment on the side you have your trackball on
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes
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

# Conway's Game of Life

# Compile for master?
MASTER_HALF ?= yes

# Enable Conway?
CONWAY_ENABLE ?= yes
# Run conway on master?
CONWAY_MASTER ?= no

# Fix kyria / split keyboard matrix. Spawn points of right half to the right
# For other split kbs, other than the SplitKB Kyria™ you may want to adjust the corresponding code.
KYRIA_MATRIX_FIX ?= yes
# Edge behaviour, kill points on edges?
EGDE_KILL ?= yes
# spawn in more random points, the longer a key is pressed. Look in conway.h to adjust interval times.
HELD_SPAWN ?= yes

ifeq ($(strip $(MASTER_HALF)), yes)
    OPT_DEFS += -DMASTER_HALF
endif
ifeq ($(strip $(CONWAY_ENABLE)), yes)
    SRC += $(USER_PATH)/conway.c
    OPT_DEFS += -DCONWAY_ENABLE
    OLED_ENABLE = yes
    OLED_DRIVER_ENABLE = yes
endif

ifeq ($(strip $(CONWAY_MASTER)), yes)
    ifeq ($(strip $(MASTER_HALF)), yes)
        CONWAY_RENDER = yes
        OPT_DEFS += -DCONWAY_RENDER
    endif
else ifeq ($(strip $(CONWAY_MASTER)), no)
    ifeq ($(strip $(MASTER_HALF)), no)
        CONWAY_RENDER = yes
        OPT_DEFS += -DCONWAY_RENDER
    endif
endif
ifeq ($(strip $(KYRIA_MATRIX_FIX)), yes)
    OPT_DEFS += -DKYRIA_MATRIX_FIX
endif
ifeq ($(strip $(EGDE_KILL)), yes)
    OPT_DEFS += -DEGDE_KILL
endif
ifeq ($(strip $(HELD_SPAWN)), yes)
    OPT_DEFS += -DHELD_SPAWN
endif
# Conway's Game of Life end
