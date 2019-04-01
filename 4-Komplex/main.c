#include<stdio.h>
#include<complex.h>
#include<tgmath.h>
//#ifdef __clang__
//#define complex _Complex double
//#endif
#include"komplex.h"
#include <stdlib.h>
#include<complex.h>
//#define RND (double)rand()/RAND_MAX
//#define ACC 1e-6
//#define EPS 1e-6

#define KOMPLEX(z) komplex_new(creal(z),cimag(z));

int main(){
  //komplex a = { RND, RND };
	//komplex b = { RND, RND };
  komplex a = {0.5, 0.3};
  komplex b = {0.4, 0.2};
	komplex z;
  komplex w;
	complex A = a.re + a.im*I;
	complex B = b.re + b.im*I;

  // KOMPLEX SET TEST
  printf("KOMPLEX SET TEST\n");
  komplex_set(&z, a.re, a.im);
  komplex_print("z= ", z);
  printf("A= (%g,%g)\n", creal(A), cimag(A));
  //komplex_print("A= ", A);
  printf("\n");

  // KOMPLEX NEW TEST
  printf("KOMPLEX NEW TEST\n");
  z = komplex_new(b.re, b.im);
  komplex_print("z= ", z);
  printf("B= (%g,%g)\n", creal(B), cimag(B));
  //komplex_print("B= ", B);
  printf("\n");

  // KOMPLEX ADD TEST
  printf("KOMPLEX ADD TEST\n");
  z = komplex_add(a, b);
  //w = (a.re + b.re) + (a.im + b.im)*I;
  w = KOMPLEX(A + B);
  komplex_print("z= ", z);
  komplex_print("w= ", w);
  printf("\n");

  // KOMPLEX SUB TEST
  printf("KOMPLEX SUB TEST\n");
  z = komplex_sub(a, b);
  //w = (a.re - b.re) + (a.im - b.im)*I;
  w = KOMPLEX(A - B);
  komplex_print("z= ", z);
  komplex_print("w= ", w);

  return 0;
}
