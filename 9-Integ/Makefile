CFLAGS = -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

.PHONEY: all
all: sol_varmeth.txt sol_int.txt

sol_int.txt: main_integ
	./$< > $@

sol_varmeth.txt: variational_method
	./$< > $@

.PHONEY: clean
clean:
	rm -f *.o *.dat
	find . -type f -executable -delete
