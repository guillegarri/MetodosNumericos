import sympy as sy
import numpy as np
import math as mt
from numpy import linalg

from GM import qr_gs_decomp, qr_gs_solve, qr_gs_inverse
from NewtonMin import newton, quasinewton

def Rosenbrock(X):
    #FX = np.empty(len(X));
    x = X[0];
    y = X[1];

    #FX[0] = (200*x**3 - 200*x*y + x - 1);
    #FX[1] = 100*(y - x**2);
    FX = (1 - x)**2 + 100*(y - x**2)**2;

    J = np.empty((len(X), len(X)));
    J[0, 0] = 400*(3*x**2 - y) + 2.0;
    J[0, 1] = -400*x;
    J[1, 0] = -400*x;
    J[1, 1] = 200;

    dfdx = np.empty(len(X));
    dfdx[0] = 400*x**3 - 400*x*y + 2*x - 2.0;
    dfdx[1] = 200*(y - x**2);
    return FX, J, dfdx;

def Himmelblau(X):
    #FX = np.empty(len(X));
    x = X[0];
    y = X[1];

    #FX[0] = 4*x*(y + x**2 - 11) + 2*x + 2*y**2 -14;
    #FX[1] = 4*y*(x + y**2 - 7) + 2*x**2 + 2*y -22;
    FX = (x**2 + y - 11)**2 + (x + y**2 - 7)**2;

    J = np.empty((len(X), len(X)));
    J[0, 0] = 4*(y + x**2 - 11) + 8*x**2 +2;
    J[0, 1] = 4*x + 4*y;
    J[1, 0] = 4*x + 4*y;
    J[1, 1] = 4*(x + y**2 - 7) + 8*y**2 +2;

    dfdx = np.empty(len(X));
    dfdx[0] = 2 * (2 * x * (x ** 2 + y - 11) + x + y ** 2 - 7);
    dfdx[1] = 2 * (x ** 2 + 2 * y * (x + y ** 2 - 7) + y - 11);
    return FX, J, dfdx;

def decay(t, u):
    return (u[0]*np.exp(-t/u[1])+u[2]);

def M_func(t, y, u, v):
    sol = 0;
    for i in range(len(t)):
        sol = sol + ((decay(t[i], v) - y[i])**2/u[i]**2);
    return np.array([sol]);
