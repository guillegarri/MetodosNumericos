import sympy as sy
import numpy as np
import math as mt

from MonteCarlo import randompoints, reg_mc

def f2d(x):
    # 2D
    return np.exp(-x[0, 0]**2-x[0, 1]**2);

D2 = 2;
N2 = 1;
a2 = np.array([-10, -10]);
b2 = np.array([10, 10]);


expec2 = mt.pi;

for i in range(11):
    N2 = 2*N2;
    S2, err2 = reg_mc(D2, a2, b2, f2d, N2);
    print('%i %g %g' % (N2, err2, 25.055/N2**0.5));
