
CFLAGS = -Wall -std=gnu1x $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

MADEFILES = main_log logistic.svg logistic.dat main_gr uplot.svg solorbit.dat circle.dat elipse.dat gr_orbit.dat elipse.svg circle.svg gr_orbit.svg

.PHONEY: all

all: logistic.svg uplot.svg elipse.svg circle.svg gr_orbit.svg

logistic.svg:logistic.gpi logistic.dat
	gnuplot $<

logistic.dat:main_log
	./$< > $@

uplot.svg: uplot.gpi solorbit.dat
	gnuplot $<

circle.svg: circle.gpi circle.dat
	gnuplot $<

elipse.svg: elipse.gpi elip.dat
	gnuplot $<

gr_orbit.svg: gr_orbit.gpi gr_orbit.dat
	gnuplot $<

circ.dat elip.dat orbit.dat: solorbit.dat
	sed -n 1,3145p solorbit.dat > circle.dat
	sed -n 3148,6292p solorbit.dat > elipse.dat
	sed -n 6295,9439p solorbit.dat > gr_orbit.dat

solorbit.dat:main_gr
	./$< > $@

.PHONEY: clean
clean:
	rm -f $(MADEFILES)
