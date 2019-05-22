import sympy as sy
import numpy as np
import math as mt
import ANN as ann

def f1(x, y=None):
    if y is None:
        return (x*np.exp(-x**2));
    else:
        return (x*y*np.exp(-y**2));

def f2(x, y=None):
    if y is None:
        return(np.cos(5*x)*np.exp(-x**2));
    else:
        return (np.cos(5*x)*np.exp(-x**2)*np.exp(-y**2));

# MAIN
nodes = 30;

# 1D
x1 = np.linspace(-2.0, 2.0, 100);
labels1 = f2(x1);

AN1 = ann.ANN1D(nodes, f1);
AN1.ann_train(x1, labels1);
y = AN1.ann_feed_forward(x1);

# 2D
#x2 = linspace(-1.5, 1.5, 100);
y2 = np.linspace(-2.5, 2.5, 100);
labels2 = f2(x1, y2);

AN2 = ann.ANN2D(nodes, f1);
AN2.ann_train([x1, y2], labels2);
z = AN2.ann_feed_forward([x1, y2]);

for i in range(100):
    print('%g %g %g %g %g %g' % (x1[i], y2[i], y[i], z[i], f2(x1[i]), f2(x1[i], y2[i])));
