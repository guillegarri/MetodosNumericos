import sympy as sy
import numpy as np

from b_search import half_int

def linterp(n, x, y, z):
    # X and Y are elements of the list (values of function) of size n
    # Z is a point in betweet the first and last element of the list X
    m = half_int(n, x, z);
    p = (y[m+1] - y[m])/(x[m+1] - x[m]);
    dx = z - x[m];
    res = y[m] + p*dx;
    return res;

def linterp_integ(n, x, y, z):
    integ = 0;
    end_integ = half_int(n, x, z);
    for i in range(end_integ):
        dx = x[i+1] - x[i];
        p = (y[i+1] - y[i])/dx;
        integ = integ + y[i]*dx + 0.5*p*dx**2;

    dx = z - x[end_integ];
    p = (y[end_integ+1] - y[end_integ])/(x[end_integ+1] - x[end_integ]);
    integ = integ + y[end_integ]*dx + 0.5*p*dx**2;
    return integ;
