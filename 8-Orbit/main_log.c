#include<stdio.h>
#include<math.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>

int log_ode(double x, const double y[], double dydx[], void* params){
  dydx[0] = y[0] * (1.0 - y[0]);
  return GSL_SUCCESS;
}

double my_log(double x){
  gsl_odeiv2_system sys;
	sys.function = log_ode;
	sys.dimension = 1;
	sys.jacobian = NULL;
	sys.params = NULL;

  double acc = 1e-6;
  double eps = 1e-6;
  double start = copysign(0.1, x);
  gsl_odeiv2_driver* driver = gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45, start, acc, eps);

  double t = 0;
  double y[1] = {0.5}; // Initial condition //
  gsl_odeiv2_driver_apply(driver, &t, x, y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}


// MAIN //
int main(){
  for (int x = 0; x < 300; x++){ // from 0 to 3 //
    printf("%g %g \n", x/100.0, my_log(x/100.0) );
  }
  printf("\n\n");

  for (int x = 0; x < 30; x++) { // from 0 to 3 //
    printf("%g %g \n", x/10.0, 1/(1+exp(-x/10.0)) );
  }
  return 0;
}
