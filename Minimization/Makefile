PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: data.txt plot_fit.svg decaydat.txt

plot_fit.svg: plot_fit.gpi data.txt decaydat.txt
	$(PLOTTER) $<

decaydat.txt: decaydat.py
	$(PYTHON) $< > $@

data.txt: main_min.py GM.py functionsMin.py NewtonMin.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
