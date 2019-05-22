#include<gsl/gsl_vector.h>
#include<gsl/gsl_multiroots.h>
#include<math.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include "stdio.h"
#include<assert.h>

int Hy_ode(double r, const double y[], double dydx[], void* params){
  double eps = *(double *) params;
  dydx[0] = y[1];
  dydx[1] = -2*(eps*y[0]+y[0]/r);
  return GSL_SUCCESS;
}

int state(int iter, gsl_multiroot_fsolver * s){
  fprintf (stderr, "iter = %3i x = % .10g f(x) = % .10g \n", iter, gsl_vector_get(s->x, 0), gsl_vector_get(s->f, 0));
	return 0;
}

double my_Hy(double r, double eps){
  assert(r >= 0);
  const double rmin = 1e-3;
  if (r < rmin){return r-r*r;}

  gsl_odeiv2_system system;
  system.function = Hy_ode;
  system.dimension = 2;
  system.jacobian = NULL;
  system.params = (void*) &eps;

  double start = copysign(1e-3, r);
  double acc = 1e-6;
  double epss = 1e-6;
  gsl_odeiv2_driver* driver = gsl_odeiv2_driver_alloc_y_new(&system, gsl_odeiv2_step_rkf45, start, acc, epss);

  double t = rmin;
  double y[] = {t-t*t, 1-2*t};
  int stats = gsl_odeiv2_driver_apply(driver, &t, r, y);
  if (stats != GSL_SUCCESS){fprintf(stderr,"Fe: odeiv2 error: %d\n", stats);}

  gsl_odeiv2_driver_free(driver);
	return y[0];
}

int M_func(const gsl_vector* current_point, void* params, gsl_vector* M){
  double rmax = *(double *) params;
  double eps = gsl_vector_get(current_point, 0);
  assert(eps < 0);
  gsl_vector_set(M, 0, my_Hy(rmax, eps));
  return GSL_SUCCESS;
}

// MAIN //
int main(int argc, char const *argv[]){
  const gsl_multiroot_fsolver_type *T;
	gsl_multiroot_fsolver *solv;

	int dim = 1;
  double rmax = 8.0;
	gsl_multiroot_function F;
	F.f = M_func;
	F.n = dim;
  F.params = (void*) &rmax;
  int status;
  int iter = 0;
  double eps_i = -14;
  gsl_vector *X = gsl_vector_alloc(dim);
  gsl_vector_set(X, 0, eps_i);

  T = gsl_multiroot_fsolver_hybrids;
  solv = gsl_multiroot_fsolver_alloc(T, dim);
  gsl_multiroot_fsolver_set(solv, &F, X);
  state(iter, solv);

  do {
		iter++;
		status = gsl_multiroot_fsolver_iterate(solv);
		state(iter, solv);
		if (status)
			break;

		status = gsl_multiroot_test_residual(solv->f, 1e-3);

	} while(status == GSL_CONTINUE && iter < 10000);

  double eps = gsl_vector_get(solv->x, 0);
  printf("epsilon = %g\n", eps);
  printf("\n\n");

  for(double r = 0; r <= rmax; r += rmax/64) printf("%g %g %g\n", r, my_Hy(r, eps), r*exp(-r));
  gsl_multiroot_fsolver_free(solv);
  gsl_vector_free(X);
  return 0;
}
