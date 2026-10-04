# Cyber5eagull - Linux port of the decompiled Windows game.
CC ?= gcc
SDL_CFLAGS := $(shell sdl2-config --cflags 2>/dev/null)
SDL_LIBS := $(shell sdl2-config --libs 2>/dev/null || echo -lSDL2)
# -ffp-contract=off keeps float rounding identical to the original's
# separate multiply/add instructions (explicit fmaf() is used where it fused them).
CFLAGS ?= -O2 -g
CFLAGS += -std=gnu11 -Wall -Wextra -Wno-unused-parameter -ffp-contract=off -fno-strict-aliasing $(SDL_CFLAGS)
LDLIBS += $(SDL_LIBS) -lm

SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=build/%.o)

all: cyberseagull

cyberseagull: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: src/%.c src/*.h src/*.inc | build
	$(CC) $(CFLAGS) -c -o $@ $<

build:
	mkdir -p build

clean:
	rm -rf build cyberseagull

.PHONY: all clean
