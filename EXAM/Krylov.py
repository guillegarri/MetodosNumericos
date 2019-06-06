import sympy as sy
import numpy as np
import math as mt

from numpy import linalg
from Gram_Schmidt import qr_gs_decomp, qr_gs_solve, qr_gs_inverse

def inverse_iteration(A, s):
    iter = 1000;
    tol = 1e-6;
    (n, m) = np.shape(A);
    A_shift = A - s*np.identity(n);
    Q, R = qr_gs_decomp(A_shift);

    eigenvec_old = np.ones(n); # Starting point for the eigenvector
    eigenvec = eigenvec_old/np.linalg.norm(eigenvec_old);

    vector = qr_gs_solve(Q, R, eigenvec);

    # Using Rayleigh quotient
    eigenval_old = np.dot(eigenvec.T, vector)/np.dot(eigenvec.T, eigenvec);
    eigenval_new = 0.0;

    for i in range(iter):
        eigenvec = vector/np.linalg.norm(vector);
        vector = qr_gs_solve(Q, R, eigenvec);

        # Using Rayleigh quotient -----> New eigenvalue
        eigenval_new = np.dot(eigenvec.T, vector)/np.dot(eigenvec.T, eigenvec);

        # Convergence condition
        if (abs((eigenval_new-eigenval_old)/eigenval_new) < tol):
            print('Convergence found after %i iterations.' % (i)); # Convergence found
            return s + 1/eigenval_new, eigenvec;

        # If convergence not found: continue
        eigenval_old = eigenval_new;

    # No convergence found after all iterations
    return ('NO CONVERGENCE');
