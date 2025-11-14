# Makefile for Finder-App
# Author: Josh Lalonde

# Compiler and flags
CC := $(CROSS_COMPILER)gcc
CFLAGS := -Wall -Werror -g -O2

all: writer

writer: writer.o
	$(CC) $(CFLAGS) -o $@ $<

writer.o: writer.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o writer