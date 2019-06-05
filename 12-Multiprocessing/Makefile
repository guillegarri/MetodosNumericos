CFLAGS = -Wall -std=gnu99 -pthread
LDLIBS = -lm -lpthread

.PHONEY: all

all: pthread.txt main

pthread.txt: main
	./$< > $@

main: main.c

.PHONEY: clean
clean:
	find . -type f -executable -delete
	rm *.txt
