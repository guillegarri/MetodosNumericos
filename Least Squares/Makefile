PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: data.txt plot_ls.svg

plot_ls.svg: plot_ls.gpi data.txt
	$(PLOTTER) $<

data.txt: main_fit.py GM.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
