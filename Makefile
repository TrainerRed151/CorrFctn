#Copyright © 2016 Brian Pomerantz. All Rights Reserved.

CC = gcc
CFLAGS = -Wall
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = run

USER_DEFINES=

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(USER_DEFINES)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
