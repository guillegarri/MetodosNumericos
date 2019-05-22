#include<gsl/gsl_vector.h>
#include<gsl/gsl_multiroots.h>
#include<math.h>
#include "stdio.h"

double Grad_RosenX(double x, double y){
	return 2*(200*x*x*x - 200*x*y + x - 1);}

double Grad_RosenY(double x, double y){
	return 200*(y-x*x);}

int state(int iter, gsl_multiroot_fsolver * s){
  printf ("iter = %3u x = % .3f % .3f ; f(x) = % .3e % .3e\n", iter, gsl_vector_get (s->x, 0), gsl_vector_get (s->x, 1), gsl_vector_get (s->f, 0), gsl_vector_get (s->f, 1));
	return 0;}

int root_eq(const gsl_vector* point, void* params, gsl_vector* f){
	double x = gsl_vector_get(point, 0);
  double y = gsl_vector_get(point, 1);
	gsl_vector_set(f, 0, Grad_RosenX(x, y));
	gsl_vector_set(f, 1, Grad_RosenY(x, y));
	return GSL_SUCCESS;}

// MAIN //
int main(int argc, char const *argv[]){
	const gsl_multiroot_fsolver_type *T;
	gsl_multiroot_fsolver *s;
	int dim = 2;

	gsl_multiroot_function F;
	F.f = root_eq;
	F.n = dim;
	int stat;
	int iter = 0;

	double xy_i[2] = {3.0, -2.0};
	gsl_vector *xy = gsl_vector_alloc(dim);
	gsl_vector_set(xy, 0, xy_i[0]);
	gsl_vector_set(xy, 1, xy_i[1]);

	T = gsl_multiroot_fsolver_hybrids;
	s = gsl_multiroot_fsolver_alloc(T, 2);
	gsl_multiroot_fsolver_set(s, &F, xy);
	state(iter, s);

	do{
		iter++;
		stat = gsl_multiroot_fsolver_iterate(s);
		state(iter, s);
		if (stat)
			break;

		stat = gsl_multiroot_test_residual(s->f, 1e-7);
	} while(stat == GSL_CONTINUE && iter < 10000);
	printf("status = %s\n", gsl_strerror(stat));
	return 0;
	}
