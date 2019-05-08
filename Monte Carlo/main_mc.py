import sympy as sy
import numpy as np
import math as mt

from MonteCarlo import randompoints, reg_mc

def f1d(x):
    # 1D
    return np.sqrt(x);

def f2d(x):
    # 2D
    return np.exp(-x[0, 0]**2-x[0, 1]**2);

def f3d(x):
    # 3D
    return 1/((1-np.cos(x[0, 0])*np.sin(x[0, 1])*np.cos(x[0, 2]))*mt.pi**3);

print('MONTE CARLO METHOD FOR A 1D TEST FUNCTION\n');
D1 = 1;
N1 = int(1e5);
a1 = np.array([0]);
b1 = np.array([1]);

S1, err1 = reg_mc(D1, a1, b1, f1d, N1);
expec1 = 2.0/3;

print('Monte Carlo result: ', S1);
print('Analytical result: ', expec1);
print('Monte Carlo error: ', err1);
print('Real error: ', np.fabs(expec1 - S1));

print('\nMONTE CARLO METHOD FOR A 2D TEST FUNCTION\n');
D2 = 2;
N2 = int(1e5);
a2 = np.array([-10, -10]);
b2 = np.array([10, 10]);

S2, err2 = reg_mc(D2, a2, b2, f2d, N2);
expec2 = mt.pi;

print('Monte Carlo result: ', S2);
print('Analytical result: ', expec2);
print('Monte Carlo error: ', err2);
print('Real error: ', np.fabs(expec2 - S2));

print('\nMONTE CARLO METHOD FOR THE 3D FUNCTION\n');
D3 = 3;
N3 = int(1e5);
a3 = np.array([0, 0, 0]);
b3 = np.array([mt.pi, mt.pi, mt.pi]);

S3, err3 = reg_mc(D3, a3, b3, f3d, N3);
expec3 = 1.393203929685;

print('Monte Carlo result: ', S3);
print('Analytical result: ', expec3);
print('Monte Carlo error: ', err3);
print('Real error: ', np.fabs(expec3 - S3));
