PROJECT_ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BUILD_DIR    := $(abspath $(CURDIR))
BUILD_SUB    ?= linux

ifeq ($(abspath $(PROJECT_ROOT)),$(BUILD_DIR))
	CREATE_BUILD_DIR := yes
else
	CREATE_BUILD_DIR := no
endif

ifeq ($(BUILD_MODE),debug)
	ifeq ($(CREATE_BUILD_DIR),yes)
		BUILD_DIR := $(BUILD_DIR)/build/debug.$(BUILD_SUB)
	endif
	CFLAGS += -g -O1 -Wall -Wextra -fsanitize=address,undefined -fno-omit-frame-pointer
	LDFLAGS += -fsanitize=address,undefined
else
	ifeq ($(CREATE_BUILD_DIR),yes)
		BUILD_DIR := $(BUILD_DIR)/build/release.$(BUILD_SUB)
	endif
	CFLAGS += -O2
endif

TARGET        := $(BUILD_DIR)/acatest
BUILD_OBJ_DIR := $(BUILD_DIR)/obj/

SRC_LIB  := $(wildcard $(PROJECT_ROOT)src/*.c)
SRC_TST  := $(wildcard $(PROJECT_ROOT)test/*.c)

OBJS_LIB := $(patsubst $(PROJECT_ROOT)src/%.c,  $(BUILD_OBJ_DIR)%.o, $(SRC_LIB))
OBJS_TST := $(patsubst $(PROJECT_ROOT)test/%.c, $(BUILD_OBJ_DIR)%.o, $(SRC_TST))


# dependency tracking
CFLAGS += -MMD -MP

.PHONY: all test clean

all: $(TARGET)

test: $(TARGET)
	$(TARGET)

$(TARGET): $(OBJS_LIB) $(OBJS_TST)
	$(CC) $(LDFLAGS) -o $@ $(OBJS_LIB) $(OBJS_TST)

$(OBJS_LIB): $(BUILD_OBJ_DIR)%.o: $(PROJECT_ROOT)src/%.c
	@mkdir -p $(dir $@)
	$(CC) -I$(PROJECT_ROOT)include -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(OBJS_TST): $(BUILD_OBJ_DIR)%.o: $(PROJECT_ROOT)test/%.c
	@mkdir -p $(dir $@)
	$(CC) -I$(PROJECT_ROOT)include -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(OBJS): $(BUILD_OBJ_DIR)%.o: $(PROJECT_ROOT)src/%.c
	@mkdir -p $(dir $@)
	$(CC) -I$(PROJECT_ROOT)include -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include $(OBJS_LIB:.o=.d) $(OBJS_TST:.o=.d)

clean:
	rm -rf $(BUILD_DIR)
