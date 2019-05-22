CFLAGS = -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)
PARAMS = -3 3 0.2

.PHONEY: all
all: document.pdf view

view: document.pdf
	xdg-open $<

document.pdf: document.tex plot.tex
	pdflatex document.tex
	pdflatex document.tex

plot.tex: plot.gpi data.txt
	gnuplot $<

data.txt: errorfunction
	./$< $(PARAMS) > $@

errorfunction: errorfunction.c

.PHONEY: clean
clean:
	find . -type f -executable -delete
	rm *.txt
	rm *.pdf
	rm plot.tex
