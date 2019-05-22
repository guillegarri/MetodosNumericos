import sympy as sy
import numpy as np
import math as mt
#import scipy as sy
import scipy.optimize as optim



class ANN1D:
    def __init__(self, nn, function):
        self.n = nn; # number of nodes
        self.dat = np.random.rand(self.n, 3);
        self.f = function;

    def ann_feed_forward(self, input):
        x = input;
        out = 0.0;
        for i in range(self.n):
            a = self.dat[i][0];
            b = self.dat[i][1];
            c = self.dat[i][2];
            out = out + self.f((x-a)/b)*c;

        return out;

    def ann_train(self, indat, l):
        assert indat.size == l.size;

        def cst_f(q):
            self.dat = np.reshape(q, (self.n, 3));
            f = l;
            y = self.ann_feed_forward(indat);
            cst = np.sum((y - f)**2);

            return cst;

        # Python's minimization routine
        optim.minimize(cst_f, np.random.rand(3*self.n), method = 'BFGS', tol = 1e-6);

class ANN2D:
    def __init__(self, nn, function):
        self.n = nn; # number of nodes
        self.dat = np.random.rand(self.n, 5);
        self.f = function;

    def ann_feed_forward(self, input):
        x = input[0];
        y = input[1];
        out = 0.0;
        for i in range(self.n):
            a = self.dat[i][0];
            b = self.dat[i][1];
            c = self.dat[i][2];
            d = self.dat[i][3];
            e = self.dat[i][4];
            out = out + self.f((x-a)/b, (x-c)/d)*e;

        return out;

    def ann_train(self, indat, l):
        # assert indat.size == l.size;

        def cst_f(q):
            self.dat = np.reshape(q, (self.n, 5));
            f = l;
            z = self.ann_feed_forward(indat);
            cst = np.sum((z - f)**2);

            return cst;

        # Python's minimization routine
        optim.minimize(cst_f, np.random.rand(5*self.n), method = 'BFGS', tol = 1e-6);
