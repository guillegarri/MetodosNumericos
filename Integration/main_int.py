import sympy as sy
import numpy as np
import math as mt
from numpy import linalg
import sys
sys.setrecursionlimit(100000)

from Integration import ra_integrator, integrator, inf_integrator, ClenshawCurtis

def sqrt(x):
    global calls1;
    calls1 = calls1 + 1;
    return x**0.5;

def sqrtinv(x):
    global calls2;
    calls2 = calls2 + 1;
    return 1.0/x**0.5;

def lnvsqrt(x):
    global calls3;
    calls3 = calls3 + 1;
    return np.log(x)/x**0.5;

def func_test(x):
    global calls4;
    calls4 = calls4 + 1;
    return 4.0*(1 - (1 - x)**2)**0.5;

def gaussian(x):
    global calls5;
    calls5 = calls5 + 1;
    return np.exp(-x**2);

# MAIN
print('FUNCTIONS INTEGRATED VIA RECURSIVE ADAPTIVE INTEGRATOR');
a = 0.0;
b = 1.0;
acc = 1e-8;
eps = 1e-8;

calls1 = 0;
error1 = 0.0;
print('\n**** SQRT integration from 0 to 1 ****');
Sol_sqrt = integrator(sqrt, a, b, acc, eps, error1);

print('\nNumerical solution: ', Sol_sqrt);
print('Analytical solution: ', 2.0/3.0);
print('The function has been called %i times.' % (calls1));
print('Estimated error: ', acc + np.fabs(Sol_sqrt)*eps);
print('Actual error: ', np.fabs(Sol_sqrt - 2.0/3.0));


calls2 = 0;
error2 = 0.0;
print('\n**** INVERSE SQRT integration from 0 to 1 ****');
Sol_sqrtinv = integrator(sqrtinv, a, b, acc, eps, error2);

print('\nNumerical solution: ', Sol_sqrtinv);
print('Analytical solution: ', 2.0);
print('The function has been called %i times.' % (calls2));
print('Estimated error: ', acc + np.fabs(Sol_sqrtinv)*eps);
print('Actual error: ', np.fabs(Sol_sqrtinv - 2.0));


calls3 = 0;
error3 = 0.0;
print('\n**** LOG/SQRT integration from 0 to 1 ****');
Sol_logsqrt = integrator(lnvsqrt, a, b, acc, eps, error3);

print('\nNumerical solution: ', Sol_logsqrt);
print('Analytical solution: ', -4.0);
print('The function has been called %i times.' % (calls3));
print('Estimated error: ',  acc + np.fabs(Sol_logsqrt)*eps);
print('Actual error: ', np.fabs(Sol_logsqrt + 4.0));


calls4 = 0;
error4 = 0.0;
print('\n**** TEST FUNCTION integration from 0 to 1 ****');
Sol_funct = integrator(func_test, a, b, acc, eps, error4);

print('\nNumerical solution: ', Sol_funct);
print('Analytical solution: ', mt.pi);
print('The function has been called %i times.' % (calls4));
print('Estimated error: ', acc + np.fabs(Sol_funct)*eps);
print('Actual error: ', np.fabs(Sol_funct - mt.pi));


#############################################################################################
print('\nFUNCTIONS INTEGRATED VIA RECURSIVE CLENSHAW-CURTIS VARIABLE TRANSFORMATION');
calls2 = 0;
error2 = 0.0;
print('\n**** INVERSE SQRT integration from 0 to 1 with CC method ****');
cc_sqrtinv = ClenshawCurtis(sqrtinv, a, b, acc, eps, error2);

print('\nNumerical solution: ', cc_sqrtinv);
print('Analytical solution: ', 2.0);
print('The function has been called %i times.' % (calls2));
print('Estimated error: ',  acc + np.fabs(cc_sqrtinv)*eps);
print('Actual error: ', np.fabs(cc_sqrtinv - 2.0));


calls4 = 0;
error4 = 0.0;
print('\n**** TEST FUNCTION integration from 0 to 1 with CC method ****');
cc_funct = ClenshawCurtis(func_test, a, b, acc, eps, error4);

print('\nNumerical solution: ', cc_funct);
print('Analytical solution: ', mt.pi);
print('The function has been called %i times.' % (calls4));
print('Estimated error: ', acc + np.fabs(cc_funct)*eps);
print('Actual error: ', np.fabs(cc_funct - mt.pi));


#############################################################################################
#inf = 1e10;
inf = float('Infinity')

print('\nFUNCTIONS WITH INFINITE LIMITS INTEGRATED');

calls5 = 0;
error5 = 0.0;
print('\n**** GAUSSIAN FUNCTION integration from zero to +infinity ****');
zi_gaus = inf_integrator(gaussian, 0, inf, acc, eps, error5);

print('\nNumerical solution: ', zi_gaus);
print('Analytical solution: ', mt.pi**0.5/2);
print('The function has been called %i times.' % (calls5));
print('Estimated error: ', acc + np.fabs(zi_gaus)*eps);
print('Actual error: ', np.fabs(zi_gaus - mt.pi**0.5/2));

calls5 = 0;
error5 = 0.0;
print('\n**** GAUSSIAN FUNCTION integration from -infinity to zero ****');
iz_gaus = inf_integrator(gaussian, -inf, 0, acc, eps, error5);

print('\nNumerical solution: ', iz_gaus);
print('Analytical solution: ', mt.pi**0.5/2);
print('The function has been called %i times.' % (calls5));
print('Estimated error: ', acc + np.fabs(iz_gaus)*eps);
print('Actual error: ', np.fabs(iz_gaus - mt.pi**0.5/2));

calls5 = 0;
error5 = 0.0;
print('\n**** GAUSSIAN FUNCTION integration from -infinity to +infinity ****');
ii_gaus = inf_integrator(gaussian, -inf, inf, acc, eps, error5);

print('\nNumerical solution: ', ii_gaus);
print('Analytical solution: ', mt.pi**0.5);
print('The function has been called %i times.' % (calls5));
print('Estimated error: ', acc + np.fabs(ii_gaus)*eps);
print('Actual error: ', np.fabs(ii_gaus - mt.pi**0.5));
