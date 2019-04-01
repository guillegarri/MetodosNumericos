CFLAGS = -Wall -std=gnu99
LDLIBS = -lm
CC = gcc

.PHONEY: default clean

default: out.txt
	cat $<

out.txt: epsilon # main
	./$< > $@

epsilon: epsilon.o function3.o

epsilon.o function3.o: function3.h

clean:
	$(RM) epsilon epsilon.o function3.o out.txt # main #out.txt
