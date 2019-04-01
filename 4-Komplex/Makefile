#CFLAGS = -Wall -std=c99 -O
#LDLIBS = -lm

#CC = gcc

#.PHONEY:all
#all              : out.txt          ; cat $<           # "$<" is the first prerequisite
#out.txt          : main             ; ./$< > $@        # "$@" is the target
#main             : main.o komplex.o # built-in linking rule is used here
#main.o komplex.o : komplex.h        # built-in compilation rule is used here

#.PHONEY:clean
#clean            :                  ; $(RM) main out* *.o *~

#STYLE = --linux-style
#.PHONEY:indent
#indent           :                  ; indent $(STYLE) main.c komplex.c; rm -f *.c~


CFLAGS = -Wall -std=gnu99 -O
LDLIBS = -lm
CC = gcc

.PHONEY: all clean
all: out.txt
	cat $<

out.txt: main
	./$< > $@

main: main.o komplex.o              # built-in linking rule is used here

main.o komplex.o: komplex.h         # built-in compiling rule is used here

clean:
	$(RM) main main.o komplex.o out.txt
