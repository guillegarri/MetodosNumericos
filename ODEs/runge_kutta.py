import sympy as sy
import numpy as np
import math as mt
from numpy import linalg

def rk_step12(f, t, h, y):
    k1 = f(y);
    k2 = f(y + k1*(h*0.5))#, t + h*0.5)
    yh = y + k2*h
    ER = np.linalg.norm((k1 - k2)*(h*0.5))
    return yh, ER;

def rk_driver(f, y, t, b, h, eps, acc):
    steps = 0;
    a = t[-1]; # count from the end of the list

    while (steps < 999):
        t0 = t[-1];
        y0 = y[-1];

        if (t0 >= b):
            break;
        if (t0 + h > b):
            h = b - t0;
            #global ERR;
        (Y, ERR) = rk_step12(f, t0, h, y0);
        tol = (acc + np.linalg.norm(Y)*eps)*(h/(b - a))**0.5;
        if (ERR < tol):
            steps = steps + 1;
            t = np.append(t, (t0 + h));
            y.append(Y);
            #y = Y;
        elif (ERR == 0):
            h = h*2;
        else:
            h = h*0.95*(tol/ERR)**0.25;
    # T and Y vlues stored in lists t and y
    return t, y;

def rk_int(f, y, t, b, h, eps, acc):
    #y[0] = 0;
    INT = h*0.5*(f(t) + f(b));
    (t, y) = rk_driver(f, y, t, b, h, eps, acc);
    for i in range(len(t)):
        INT = INT + h*f(t + i*h);
    return INT;
