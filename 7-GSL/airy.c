#include<stdio.h>
#include<gsl/gsl_sf_airy.h>
//#include<gsl/gsl_sf_airy_Bi.h>
#include<math.h>

int main(){
  for(double x=-15.0; x<5.0; x+=0.01){
    printf("%g %g %g\n", x, gsl_sf_airy_Ai(x, 0), gsl_sf_airy_Bi(x, 0));
  }
return 0;
}
