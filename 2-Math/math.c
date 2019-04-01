#include<stdio.h>
#include<math.h>
// #include<tgmath.h>
#include<complex.h> // I defined as the Complex Unit

#define E 2.7182818284590452354 /* e */
#define PI 3.1415926536897932384 /* pi */
// Calculate GammaFunction(5), BesselFunction_1(0.5) & sqrt(-2), exp(i), exp(i*pi), i^e

int main(){
  double x1 = 5;
  double y1 = tgamma(x1);
  printf("Gamma(5) = %g\n",y1);

  double x2 = 0.5;
  double y2 = j1(x2);
  printf("J_1(0.5) = %g\n",y2);
  printf("\n");

  double x3 = -2;
  double complex z1 = csqrt(x3);
  printf("Square root of -2:     %g%+gi\n", creal(z1), cimag(z1));

  double complex z_2 = I;
  double complex z2 = cexp(z_2);
  printf("Exponential of i:      %g%+gi\n", creal(z2), cimag(z2));

  double complex z_3 = PI*I;
  double complex z3 = cexp(z_3);
  printf("Exponential of i*pi:   %g%+gi\n", creal(z3), cimag(z3));

  double complex z_4 = I;
  double complex z_5 = E;
  double complex z4 = cpow(z_4, z_5);
  printf("i to the power of e:   %g%+gi\n", creal(z4), cimag(z4));
  printf("\n");

  float y_1 = 0.1111111111111111111111111111;
  double y_2 = 0.1111111111111111111111111111;
  long double y_3 = 0.1111111111111111111111111111L;

  printf("Float:       %.25g\n", y_1);
  printf("Double:      %.25g\n", y_2);
  printf("Long double: %.25Lg\n", y_3);

  return 0;
}
