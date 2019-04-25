import sympy as sy
import numpy as np
import math as mt

for i in range(200):
    print('%g %g %g' % (i*mt.pi/100.0, np.sin(i*mt.pi/100.0), np.cos(i*mt.pi/100.0)));
    # x, f [sin], df [cos]
