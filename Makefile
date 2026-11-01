PROJECT_ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BUILD_DIR    := $(abspath $(CURDIR))

ifeq ($(abspath $(PROJECT_ROOT)),$(BUILD_DIR))
	CREATE_BUILD_DIR := yes
else
	CREATE_BUILD_DIR := no
endif

ifeq ($(BUILD_MODE),debug)
	ifeq ($(CREATE_BUILD_DIR),yes)
		BUILD_DIR := $(BUILD_DIR)/build/debug.linux/
	endif
	CFLAGS += -g -O1 -Wall -Wextra -fno-omit-frame-pointer
else
	ifeq ($(CREATE_BUILD_DIR),yes)
		BUILD_DIR := $(BUILD_DIR)/build/release.linux/
	endif
	CFLAGS += -O2
endif

BUILD_OBJ_DIR := $(BUILD_DIR)/obj/

SRC  := $(wildcard $(PROJECT_ROOT)src/*.c)
OBJS := $(patsubst $(PROJECT_ROOT)src/%.c,$(BUILD_OBJ_DIR)%.o,$(SRC))

STATIC_LIB = $(BUILD_DIR)/libaca.a
SHARED_LIB = $(BUILD_DIR)/libaca.so

# shared library
CFLAGS += -fPIC
# dependency tracking
CFLAGS += -MMD -MP

.PHONY: all static shared clean

all: static shared

static: $(STATIC_LIB)

shared: $(SHARED_LIB)

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJS)
	$(CC) -shared $(LDFLAGS) -o $@ $^

$(OBJS): $(BUILD_OBJ_DIR)%.o: $(PROJECT_ROOT)src/%.c
	@mkdir -p $(dir $@)
	$(CC) -I$(PROJECT_ROOT)include -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR)
