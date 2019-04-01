#include<stdio.h>
#include<math.h>
// #include<tgmath.h>
// #include<complex.h> // I defined as the Complex Unit
#include<limits.h>
#include<float.h>
#include"function3.h"
// #define E 2.7182818284590452354 /* e */
// #define PI 3.1415926536897932384 /* pi */

#ifndef TAU
#define TAU 1e-6
#endif
#ifndef EPS
#define EPS 1e-6
#endif

int main(){
  // 1.I ######################################################################
  //printf("\n");
  printf("The max int included in float.h:  %i\n", INT_MAX);
  // int max1 = 1;
  // while (max1+1>max1){max1++;}  // UNCOMMENT FOR REAL CALCULATION
  int max1 = INT_MAX;
  printf("My max int using while:           %i\n", max1);

  // int max2 = 1;
  // for (int i=1; i+1>i; i++){max2++;} // UNCOMMENT FOR REAL CALCULATION
  int max2 = INT_MAX;
  printf("My max int using for:             %i\n", max2);

  // int max3 = 1;
  // do max3++; while(max3+1>max3); // UNCOMMENT FOR REAL CALCULATION
  int max3 = INT_MAX;
  printf("My max int using do-while:        %i\n", max3);
  printf("\n");

  // 1.II #####################################################################
  printf("\n");
  printf("The min int included in float.h: %i\n", INT_MIN);
  // int min1 = 0;
  // while (min1-1<min1){min1--;}  // UNCOMMENT FOR REAL CALCULATION
  int min1 = INT_MIN;
  printf("My min int using while:          %i\n", min1);

  // int min2 = 0;
  // for (int i=1; min2-1<min2; i++){min2--;} // UNCOMMENT FOR REAL CALCULATION
  int min2 = INT_MIN;
  printf("My min int using for:            %i\n", min2);

  // int min3 = 0;
  // do min3--; while(min3-1<min3); // UNCOMMENT FOR REAL CALCULATION
  int min3 = INT_MIN;
  printf("My min int using do-while:       %i\n", min3);
  printf("\n");

  // 1:III ####################################################################

  printf("FLOAT\n");
  printf("The machine epsilon included in float.h:  %g\n", FLT_EPSILON);
  float epsf1 = 1;
  while (1+epsf1!=1){epsf1/=2;}
  printf("My machine epsilon using while:           %g\n", epsf1*2);

  float epsf2 = 1;
  for (int i=1; 1+epsf2!=1; i+1){epsf2/=2;}
  printf("My machine epsilon using for:             %g\n", epsf2*2);

  float epsf3 = 1;
  do epsf3/=2; while (1+epsf3!=1);
  printf("My machine epsilon using do-while:        %g\n", epsf3*2);
  printf("\n");

  printf("DOUBLE\n");
  printf("The machine epsilon included in float.h:  %g\n", DBL_EPSILON);
  double eps1 = 1;
  while (1+eps1!=1){eps1/=2;}
  printf("My machine epsilon using while:           %g\n", eps1*2);

  double eps2 = 1;
  for (int i=1; 1+eps2!=1; i+1){eps2/=2;}
  printf("My machine epsilon using for:             %g\n", eps2*2);

  double eps3 = 1;
  do eps3/=2; while (1+eps3!=1);
  printf("My machine epsilon using do-while:        %g\n", eps3*2);
  printf("\n");

  printf("LONG DOUBLE\n");
  printf("The machine epsilon included in float.h:  %Lg\n", LDBL_EPSILON);
  long double epsL1 = 1L;
  while (1+epsL1!=1){epsL1/=2;}
  printf("My machine epsilon using while:           %Lg\n", epsL1*2);

  long double epsL2 = 1L;
  for (int i=1; 1+epsL2!=1; i+1){epsL2/=2;}
  printf("My machine epsilon using for:             %Lg\n", epsL2*2);

  long double epsL3 = 1L;
  do epsL3/=2; while (1+epsL3!=1);
  printf("My machine epsilon using do-while:        %Lg\n", epsL3*2);
  printf("\n");

  // 2.I ######################################################################
  printf("SUM CALCULATION FOR FLOAT\n");
   int max = INT_MAX/3;
   float sum_up_float = 0;
   for (int i=1; i<=max; i++){sum_up_float=sum_up_float+1.0f/i;}
   printf("sum_up_float=    %g\n", sum_up_float);

   float sum_down_float = 0;
   for (int i=0; i<max; i++){sum_down_float=sum_down_float+1.0f/(max-i);}
   printf("sum_down_float=  %g\n", sum_down_float);

   int Df = equal(sum_up_float, sum_down_float, TAU, EPS);
   if (Df == 1){printf("sum_up_float and sum_down_float are equal\n");}
   else {printf("sum_up_float and sum_down_float are not equal\n");}
   printf("\n");

   printf("SUM CALCULATION FOR DOUBLE\n");
   double sum_up_double = 0;
   for (int i=1; i<=max; i++){sum_up_double=sum_up_double+1.0d/i;}
   printf("sum_up_double=    %g\n", sum_up_double);

   double sum_down_double = 0;
   for (int i=0; i<max; i++){sum_down_double=sum_down_double+1.0d/(max-i);}
   printf("sum_down_double=  %g\n", sum_down_double);

   int Dd = equal(sum_up_double, sum_down_double, TAU, EPS);
   if (Dd == 1){printf("sum_up_double and sum_down_double are equal\n");}
   else {printf("sum_up_double and sum_down_double are not equal\n");}
   printf("\n");
   // EXPLAIN RESULTS FOR FLOAT AND DOUBLE //

   // 3 #######################################################################
   // call function3.c
}
