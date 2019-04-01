import sympy as sy
import numpy as np
from numpy import linalg

def qr_gs_decomp(A, R):
    n = len(A); # Number of lines
    m = len(A[0]); # Number of columns
    a_i = np.empty(n);
    a_j = np.empty(n);
    q_i = np.empty(n);
    for i in range(m):
        a_i = A[:, i];
        norm_a_i = np.linalg.norm(a_i);
        q_i = a_i/norm_a_i;
        R[i, i] = norm_a_i; # Diagonal values of R
        for j in range(i+1, m, 1):
            a_j = A[:, j];
            dotprod = 0;
            dotprod = np.dot(q_i, a_j);
            R[i, j] = dotprod; # Triangular superior values of R
            a_j = a_j - dotprod*q_i;
            A[:, j] = a_j;
        A[:, i] = q_i; # Creating matrix Q
    return A, R;

def qr_gs_solve(Q, R, b, x):
    m = len(R);
    Qx =np.empty(m);
    alph = 1.0;
    beta = 0.0;
    Qb = np.matmul(Q.T, b);
    for i in range(m-1, -1, -1):
        x[i] = alph*Qb[i] + beta*x[i];
        s = 0;
        for j in range(i+1, m, 1):
            s = s + R[i, j]*x[j];
        x[i] = (x[i] - s)/R[i, i];
    return x;

def qr_gs_inverse(Q, R, B): # With the Q and R matrix from A calculate its inverse
    n = len(Q);
    bb = np.zeros(n);
    xx = np.empty(n);
    for i in range(n):
        bb[i] = 1.0;
        qr_gs_solve(Q, R, bb, xx);
        bb[i] = 0.0;
        B[:, i] = xx;
    return B;

# GKL Bidiagonalization should be solved as the inverse calculation. But with
# alpha and beta instead of vectors of ones and zeros
