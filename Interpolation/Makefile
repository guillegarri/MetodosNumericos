PYTHON = python3
PLOTTER = gnuplot

.PHONEY: all
all: Plots interpolation.txt exact.txt

.PHONEY: Plots
Plots:all_splines.svg all_integrals.svg qc_derivatives.svg lin_splines.svg quad_splines.svg cub_splines.svg

lin_splines.svg: lin_splines.gpi interpolation.txt exact.txt
	$(PLOTTER) $<

quad_splines.svg: quad_splines.gpi interpolation.txt exact.txt
	$(PLOTTER) $<

cub_splines.svg: cub_splines.gpi interpolation.txt exact.txt
	$(PLOTTER) $<

all_splines.svg: all_splines.gpi interpolation.txt
	$(PLOTTER) $<

all_integrals.svg: all_integrals.gpi interpolation.txt exact.txt
	$(PLOTTER) $<

qc_derivatives.svg: qc_derivatives.gpi interpolation.txt exact.txt
	$(PLOTTER) $<

exact.txt: spline_check.py
	$(PYTHON) $< > $@

interpolation.txt: main.py b_search.py lin_spline.py quad_spline.py cubic_spline.py
	$(PYTHON) $< > $@
#	python3 main.py > interpolation.txt

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
