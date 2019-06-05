PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: rksol.txt mathsol.txt sine_rk.svg

sine_rk.svg: sine_rk.gpi rksol.txt mathsol.txt
	$(PLOTTER) $<

rksol.txt: main_ODE.py runge_kutta.py
	$(PYTHON) $< > $@

mathsol.txt: sin.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
