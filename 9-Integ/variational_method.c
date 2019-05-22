#include<gsl/gsl_integration.h>
#include<math.h>
#include<stdio.h>

double psi_os(double x,  void* params){
  double alph=*(double*)params;
  return exp(-alph*x*x);
}

double psi_Hos(double x, void* params){
  double alph=*(double*)params;
  return (-alph*alph*x*x/2 +alph/2 + x*x/2)*exp(-alph*x*x);
}

double norm_os(double alph){
  gsl_function f;
  f.function = &psi_os;
  f.params = (void*)&alph;

  size_t lim = 10;
  double acc = 1e-6;
  double eps = 1e-6;
  double result;
  double err;
	gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(lim);
	gsl_integration_qagi(&f, acc, eps, lim, workspace, &result, &err);
	gsl_integration_workspace_free(workspace);
  // The function norm_os has been called //

  return result;
}

double expH(double alph){
  gsl_function f;
  f.function = &psi_Hos;
  f.params = (void*)&alph;

  size_t lim = 10;
  double acc = 1e-6;
  double eps = 1e-6;
  double result;
  double err;
	gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(lim);
	gsl_integration_qagi(&f, acc, eps, lim, workspace, &result, &err);
	gsl_integration_workspace_free(workspace);
  // The function expH has been called //

  return result;
}

int main(){
  for (double a = 0.1; a < 5.0; a+=0.1) {
    double E = expH(a)/norm_os(a);
    printf("%g %g\n",a, E);
  }
  printf("\n");
  printf("The minimum of E = 0.5 for alph = 1.0 appears because there is a bound state for that energy.");
  return 0;
}
