import sympy as sy
import numpy as np
import math as mt

def randompoints(dim, a, b):
    #for i in range(dim):
    #    x[i] = a[i] + np.random.rand(1, len(a))*(b[i] - a[i]);

    x = a + np.random.rand(1, len(a))*(b - a);
    return x;

def reg_mc(dim, a, b, f, Npoints):
    sol = 0.0;
    err = 0.0;
    V = 1.0;
    for i in range(dim):
        V = V*(b[i] - a[i]);

    sum = 0;
    sumq = 0;
    #x = np.empty(dim);

    for i in range(Npoints):
        x = randompoints(dim, a, b);
        fval = f(x);
        sum = sum + fval;
        sumq = sumq + fval**2;

    avg = sum/Npoints;
    var = sumq/Npoints - avg**2;

    sol = avg*V;
    err = V*(var/Npoints)**0.5;

    return sol, err;
