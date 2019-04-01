#include "nvector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

nvector *nvector_alloc(int n){
  nvector *v = (nvector *) malloc(sizeof(nvector));
  //nvector *v = malloc(sizeof(nvector));
  (*v).size = n;
	(*v).data = (double *)malloc(n * sizeof(double));
  //(*v).data = malloc(n*sizeof(double));
  //if( v==NULL ){
  //  fprintf(stderr,"error in nvector_alloc\n");
  //}
  return v;
}

void nvector_free(nvector * v){
  free(v->data);
  free(v);
}

void nvector_set(nvector * v, int i, double value){
  (*v).data[i]=value;
}

double nvector_get(nvector * v, int i){
  return (*v).data[i];
}

double nvector_dot_product(nvector * u, nvector * v){
  assert(u->size == v->size);
  double s;
	for (int i = 0; i < u->size; i++){
		s += nvector_get(u, i) * nvector_get(v, i);
	}
  return s;
}
