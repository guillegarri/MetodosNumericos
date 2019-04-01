//#include "nvector.h"
#include "nvector.h"
#include <stdio.h>
#include <stdlib.h>
#define RND (double)rand()/RAND_MAX

int main(){
  int n = 5;

  // TEST NVECTOR ALLOC
  printf("TEST nvector_alloc:\n");
  nvector *v = nvector_alloc(n);
  if (v == NULL){
    printf("nvector_alloc doesn't work.\n");
  }
	else{
    printf("nvector_alloc works.\n");
  }
  printf("\n");

  // TEST NVECTOR SET AND NVECTOR GET
  printf("TEST nvector_set and nvector_get:\n");
  double val = RND;
  int i = n;
  nvector_set(v, i, val);
  double vi = nvector_get(v, i);
  if (val == vi){
    printf("nvector_set and nvector_get work.\n");
  }
  else{
    printf("nvector_set and nvector_get don't work.\n");
  }
  printf("\n");

  // TEST NVECTOR DOT PRODUCT
  printf("TEST nvector_doc_product:\n");
  nvector *u = nvector_alloc(n);
  nvector *w = nvector_alloc(n);
  double dot;
  for (int i = 0; i < n; i++){
    double val1=RND;
    double val2=RND;
    nvector_set(u, i, val1);
    nvector_set(w, i, val2);
    dot += val1 * val2;
  }

  double sol = nvector_dot_product(u, w);
  if (sol == dot){
    printf("nvector_dot_product works.\n");
  }
  else {
    printf("nvector_dot_product doesn't work.\n");
  }
  printf("\n");

  // TEST NVECTOR FREE
  printf("TEST nvector_free:\n");
  nvector_free(v);
  if (v == NULL){
    printf("nvector_free works.\n");
  }
	else{
    printf("nvector_free doesn't work.\n");
  }

  nvector_free(u);
  nvector_free(w);

  return 0;
}
