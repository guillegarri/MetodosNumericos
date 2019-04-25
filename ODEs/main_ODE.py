import sympy as sy
import numpy as np
import math as mt

from runge_kutta import rk_step12, rk_driver, rk_int

# Diferential equations that will be solve
def diff_sin(y):
    # Sin differential equation
    return np.array([y[1], -y[0]]);


def int_gauss(t):
    # gaussian integral
    return mt.exp(-t[0]**2);

# IFFERENTIAL EQUATION FOR sine
a = 0;
b = 2*mt.pi;
h = 0.1;
acc = 5e-3;
eps = 5e-3;

x0 = np.array([a]);
y = [];
y.append(np.array([0, 1]));
(T, Y) = rk_driver(diff_sin, y, x0, b, h, eps, acc);

# Print x, f, df
for i in range(len(T)):
    print(T[i], Y[i][0], Y[i][1]);

#DIFFERENTIAL EQUATION FOR GAUSSIAN INTEGRAL
a_g = -1.25;
b_g = 1.25;
h_g = 0.05;
acc_g = 5e-3;
eps_g = 5e-3;

x0_g = np.array([a_g]);
b0_g = np.array([b_g]);
I = [];
I.append(np.array([1]));

Integ = rk_int(int_gauss, I, x0_g, b0_g, h_g, eps_g, acc_g);

print('\n Result for the differential gaussian integral between %0.2f and %0.2f: %f' % (a_g, b_g, Integ));
print('Result for the differential gaussian integral between -inf and +inf: %f' % (np.sqrt(mt.pi)));
