CFLAGS = -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

PHONEY: all
all: wavefunction.svg rosenbrock.txt

wavefunction.svg: wavefunction.gpi eps.txt
	gnuplot $<

eps.txt log.txt: main_Hy
	./$< 1> eps.txt 2> log.txt

main_Hy: main_Hy.c

rosenbrock.txt: main_Rb
	./$< > $@

main_Rb: main_Rb.c

.PHONEY: clean
clean:
		find . -type f -executable -delete
		rm *.out
