import sympy as sy
import numpy as np

from b_search import half_int
from lin_spline import linterp, linterp_integ
from quad_spline import qspline_eval, qspline_deriv, qspline_integ, qspline
from cubic_spline import cspline_eval, cspline_deriv, cspline_integ, cspline

# We are using Y = X**2
# It works fine for Y=1 and Y=X
X = [0, 2, 4, 6, 8, 10];
Y = [0, 4, 16, 36, 64, 100];
N = len(X);

for i in range(100):
    z = i/10;
    print("%.1f %0.1f %0.2f %0.1f %0.3f %0.1f %0.3f %0.3f %0.3f" % (z, linterp(N, X, Y, z), linterp_integ(N, X, Y, z), qspline_eval(X, Y, z), qspline_integ(X, Y, z), qspline_deriv(X, Y, z), cspline_eval(X, Y, z), cspline_integ(X, Y, z), cspline_deriv(X, Y, z)));
