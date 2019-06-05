PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: MCsolution.txt plot_error.svg

plot_error.svg: plot_error.gpi Error.txt
	$(PLOTTER) $<

Error.txt: error.py MonteCarlo.py
	## This may take some seconds ##
	$(PYTHON) $< > $@

MCsolution.txt:	main_mc.py MonteCarlo.py
	## This may take some seconds ##
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
