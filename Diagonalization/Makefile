PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: times.svg eig_by_eig.txt cyclic.txt

times.svg: times.gpi times.txt
	$(PLOTTER) $<

cyclic.txt: main_sweeps.py Jacobi.py
	$(PYTHON) $< > $@

eig_by_eig.txt: main_eig.py Jacobi.py
	$(PYTHON) $< > $@

times.txt: main_times.py Jacobi.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
