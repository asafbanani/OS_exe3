CC = gcc
DEBUG = -g
CFLAGS = -Wall -Werror $(DEBUG)

SRC = digcmp.c lencmp.c lexcmp.c loopcmp.c
EXE = digcmp lencmp lexcmp loopcmp

.PHONY: all clean

all: $(EXE)

digcmp: digcmp.c
	$(CC) $(CFLAGS) -o $@ $<

lencmp: lencmp.c
	$(CC) $(CFLAGS) -o $@ $<

lexcmp: lexcmp.c
	$(CC) $(CFLAGS) -o $@ $<
	
loopcmp: loopcmp.c
	$(CC) $(CFLAGS) -o $@ $<
	

clean:
	rm -f $(EXE)
