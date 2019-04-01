#include<stdio.h>
#include<math.h>
// #include<tgmath.h>
// #include<complex.h> // I defined as the Complex Unit
//#include<limits.h>
#include<float.h>
//#include<stdlib.h>
#include"komplex.h"

#ifndef TAU
#define TAU 1e-6
#endif
#ifndef EPS
#define EPS 1e-6
#endif

const komplex komplex_I = { 0, 1 };

// KPOMPLEX PRINT

void komplex_print(char *s, komplex a){
	printf ("%s (%g,%g)\n", s, a.re, a.im);
}

// KOMPLEX SET

void komplex_set(komplex* z, double x, double y){
	(*z).re = x;
	(*z).im = y;
}

// KOMPLEX NEW

komplex komplex_new(double x, double y){
	komplex z = {x, y};
	return z;
}

// KOMPLEX ADD

komplex komplex_add(komplex a, komplex b){
	komplex result = {a.re + b.re , a.im + b.im};
	return result;
}

// KOMPLEX SUB

komplex komplex_sub(komplex a, komplex b){
	komplex result = {a.re - b.re , a.im - b.im};
	return result;
}

/* the following is optional */

// KOMPLEX EQUAL

// KOMPLEX MUL

// KOMPLEX DIV

// KOMPLEX CONJUGATE

// KOMPLEX ABS

// KOMPLEX EXP

// KOMPLEX SIN

// KOMPLEX COS

// KOMPLEX SQRT
