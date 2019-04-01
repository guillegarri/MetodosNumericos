import sympy as sy
import numpy as np

from gram_schmidt import qr_gs_decomp, qr_gs_solve, qr_gs_inverse

n = int(5); # Number of lines
m = int(4); # Number of columns
A = np.random.rand(n, m);
R = np.empty((m, m));

print('\nQR DECOMPOSITION\n')
print('Matrix A 5x4 randomly generated:\n');
print(A)
# Decomposition QR
qr_gs_decomp(A, R);

print('\nMatrix Q 5x4:\n');
print(A)
print('\nMatrix upper triangular R 4x4:\n');
print(R);

# Check Qt*Q = 1 and Q*R = A
print('\nCheck that Qt*Q = I:\n')
QtQ = np.matmul(A.T, A);
print(QtQ);

print('\nCheck that Q*R = A:\n')
QR = np.matmul(A, R);
print(QR);

# Linear equation solve
print('\nSOLVING LINEAL EQUATION SYSTEM\n');
ns = int(4);
x = np.empty(ns);
b = np.random.rand(ns);
AA = np.random.rand(ns, ns);
RR = np.empty((ns, ns));
print('Random matrix A:\n');
print(AA);
# Decomposition QR
qr_gs_decomp(AA, RR);

# System solving
qr_gs_solve(AA, RR, b, x);

print('\nRandom vector b:\n');
print(b);

print('\nSolution (x) of the system of linear equations A*x = Q*Rx = b:\n');
print(x);

# Check that we get b back after A*x
print('\nCheck that A*x = b:\n');
b2 = np.empty(ns);
A2 = np.matmul(AA, RR);
b2 = np.matmul(A2, x);
print(b2);

# Inverse calculation
print('\nINVERSE CALCULATION\n');
# We will use the same A matrix from the equation system
B = np.empty((ns, ns));
qr_gs_inverse(AA, RR, B);
print('Inverse matrix of A (from the lineal equation system), B:\n');
print(B);

print('\nCheck that A*B = I:\n');
I1 = np.matmul(A2, B);
print(I1);

print('\nCheck that B*A = I:\n');
I2 = np.matmul(B, A2);
print(I2);
