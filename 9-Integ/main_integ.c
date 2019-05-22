#include<gsl/gsl_integration.h>
#include<math.h>
#include<stdio.h>

double integ(double x, void* params){
  return log(x)/sqrt(x);
}

int main(int argc, char const *argv[]) {
  gsl_function f;
  f.function = &integ;
  f.params = NULL;

  size_t lim = 10;
  double acc = 1e-6;
  double eps=1e-6;
  double result;
  double err;
	gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(lim);
	gsl_integration_qags(&f, 0, 1, acc, eps, lim, workspace, &result, &err);
	gsl_integration_workspace_free(workspace);
  printf("The integral is %g with error %g\n", result, err);

  return 0;
}
