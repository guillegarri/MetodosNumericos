#include"komplex.h"
#include<stdio.h>
#include<float.h>
#include<math.h>

#ifndef TAU
#define TAU 1e-6
#endif
#ifndef EPS
#define EPS 1e-6
#endif

const komplex komplex_I = { 0, 1 };

komplex komplex_new(double x, double y)
{
	komplex z = { x, y };
	return z;
}

void komplex_set(komplex * z, double x, double y)
{
	z->re = x;
	z->im = y;
}

int double_equal(double a, double b, double acc, double eps)
{
	if (fabs(a - b) < acc)
		return 1;
	if (fabs(a - b) / (fabs(a) + fabs(b)) < eps / 2)
		return 1;
	return 0;
}

int komplex_equal(komplex a, komplex b, double acc, double eps)
{
	return double_equal(a.re, b.re, acc, eps)
	    && double_equal(a.im, b.im, acc, eps);
}

void komplex_print(char *s, komplex a)
{
	printf("%s (%g,%g)\n", s, a.re, a.im);
}

komplex komplex_add(komplex a, komplex b)
{
	komplex z = { a.re + b.re, a.im + b.im };
	return z;
}

komplex komplex_div(komplex a, komplex b)
{
	if (fabs(b.im) < fabs(b.re)) {
		double e = b.im / b.re;
		double f = b.re + b.im * e;
		komplex result =
		    {.re = (a.re + a.im * e) / f,.im = (a.im - a.re * e) / f };
		return result;
	} else {
		double e = b.re / b.im;
		double f = b.im + b.re * e;
		komplex result =
		    {.re = (a.im + a.re * e) / f,.im = (-a.re + a.im * e) / f };
		return result;
	}
}

komplex komplex_conjugate(komplex a)
{
	komplex z = { a.re, -a.im };
	return z;
}

komplex komplex_exp(komplex a)
{
	komplex z;
	z.re = cos(a.im) * exp(a.re);
	z.im = sin(a.im) * exp(a.re);
	return z;
}
