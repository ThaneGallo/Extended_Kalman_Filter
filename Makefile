# Makefile for main.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic

# Target executable
TARGET = main

# Default target
all: $(TARGET)

# Build target
$(TARGET): main.c matrix.c matrix.h
	$(CC) $(CFLAGS) -o $(TARGET) main.c matrix.c -lm

# Clean target
clean:
	rm -f $(TARGET)
