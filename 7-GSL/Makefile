CFLAGS += -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS += $$(gsl-config --libs)
#SCRIPT = airy.gpi
#FORMAT = pdf
#PLOTTER = pyxplot
#PLOTTER = gnuplot

.PHONEY: all
all: airy.pdf linear.out.txt
	cat $(word 2,$^)
airy.pdf: airy.gpi airy.data
	gnuplot $<
airy.data: airy
	./$< > $@
linear.out.txt:linear
	./$< > $@

.PHONEY: clean
clean:
	find . -type f -executable -delete
	rm -f *.o *.txt *.data *.svg
