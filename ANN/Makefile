PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: outANN.txt plot1d.svg plot2d.svg

plot2d.svg: plot2d.gpi outANN.txt
	$(PLOTTER) $<

plot1d.svg: plot1d.gpi outANN.txt
	$(PLOTTER) $<

outANN.txt: main_ann.py ANN.py
	## This may take some seconds ##
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
