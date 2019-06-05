import sympy as sy
import numpy as np
from numpy import linalg

def GKL(A):
  n = A.shape[1];
  v = np.ones(n)/np.sqrt(n);
  u = np.zeros(A.shape[0]);
  beta = 0;
  U = np.zeros_like(A);
  V = np.zeros((n,n));

  for i in range(n):
    V[:, i] = v;
    u = np.matmul(A, v) - beta*u;
    alpha = np.linalg.norm(u);
    u = u/alpha;
    U[:, i] = u;
    v = np.matmul(A.T, u) - alpha*v;
    beta = np.linalg.norm(v);
    v = v/beta;

  return U, V;

# MAIN
n = int(4);
m = int(4);
A = np.random.rand(n, m);

U, V = GKL(A);
AV = np.matmul(A, V);
B = np.matmul(U.T, AV);

print('\nGolub-Kahan-Lanczos Bidiagonalization\n');
print('Matrix A 5x4 randomly generated:\n');
print(A);

print('\nMatrix U obtained from Golub-Kahan-Lanczos Bidiagonalization process:\n')
print(U);

print('\nMatrix V obtained from Golub-Kahan-Lanczos Bidiagonalization process:\n')
print(V);

print('\nBidiagonal Matrix :\n');
print(B);

print('\n--------------')
print('\nCheck that U is orthogonal: U*U^T =\n');
print(np.matmul(U, U.T));

print('\nCheck that V is orthogonal: V*V^T =\n');
print(np.matmul(V, V.T));

#print(B);
