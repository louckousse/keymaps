LEADER_ENABLE = no        # Enable the Leader Key feature
MOUSEKEY_ENABLE = no
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no

EXTRAFLAGS += -Wno-error=unused-variable -Wno-error=unused-function
EXTRAFLAGS += -Wno-unused-function -Wno-unused-variable
EXTRAFLAGS += -flto
