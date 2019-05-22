PROGRAM   = Dush-game
CC        = gcc
PROG      = main.c lvl.c variables.c collision.c light.c
ZAG       = lvl.h variables.h collision.h light.h
CFLAGS    = -g -lm
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): $(PROG) $(ZAG)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(PROG) $(LDFLAGS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
