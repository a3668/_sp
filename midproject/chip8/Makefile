CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -g -I/opt/homebrew/include $(shell sdl2-config --cflags)
LDFLAGS := $(shell sdl2-config --libs)

SRCS    := main.c chip8.c display.c input.c
OBJS    := $(SRCS:.c=.o)
TARGET  := chip8

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)