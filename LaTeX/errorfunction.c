#include<stdio.h>
#include<math.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<stdlib.h>

int erf_ode(double x, const double y[], double dydx[], void* params){
  dydx[0] = (2.0/sqrt(M_PI))*exp(-x*x);
  return GSL_SUCCESS;
}

double erf(double x){
  gsl_odeiv2_system erfcalc;
  erfcalc.function = erf_ode;
  erfcalc.dimension = 1;
  erfcalc.jacobian = NULL;
  erfcalc.params = NULL;

  double start = copysign(0.1, x);
  double acc = 1e-6;
  double eps = 1e-6;
  gsl_odeiv2_driver* driver = gsl_odeiv2_driver_alloc_y_new(&erfcalc, gsl_odeiv2_step_rkf45, start, acc, eps);

  double t = 0;
  double y[] = {0};
  gsl_odeiv2_driver_apply(driver, &t, x, y);
	gsl_odeiv2_driver_free(driver);
	return y[0];
}

int main(int argc, char const *argv[]){
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double dx = atof(argv[3]);

  for (double x = a; x < b; x += dx){
    printf("%g %g\n", x, erf(x));}
  return 0;
}
