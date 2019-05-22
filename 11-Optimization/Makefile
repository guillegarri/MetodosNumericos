CFLAGS = -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

.PHONEY: all
all: leastsquares.svg rosenbrock.svg

leastsquares.svg: leastsquares.gpi fit.txt
	gnuplot $<

rosenbrock.svg: rosenbrock.gpi rosenbrock.txt
	gnuplot $<

fit.txt parameters.txt: main_ls
	./$< 1> fit.txt 2> parameters.txt

Rosenbrock_nMin.txt rosenbrock.txt: main_Rb
	./$< 1> Rosenbrock_Min.txt 2> rosenbrock.txt

main_Rb: main_Rb.c

main_ls: main_ls.c

.PHONEY: clean
clean:
	find . -type f -executable -delete
	rm *.txt
	rm *.svg
