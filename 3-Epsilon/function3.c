#include<stdio.h>
#include<math.h>
// #include<tgmath.h>
// #include<complex.h> // I defined as the Complex Unit
#include<limits.h>
#include<float.h>
#include"function3.h"

int equal(double a, double b, double tau, double epsilon){
  if (abs(a-b)<tau){return 1;}
  else if (abs(a-b)/(abs(a)+abs(b))<epsilon/2){return 1;}
  else return 0;
}
