import sympy as sy
import numpy as np
import math as mt

from numpy import linalg
from Gram_Schmidt import qr_gs_decomp, qr_gs_solve, qr_gs_inverse
from Krylov import inverse_iteration

X = 56; # Final two digints of student number
N = 23; # Total number of excercises
print('The exam problem to solve is: %g.' % (X % N));
print('"Inverse iteration algorithm for eigenvalues (and eigenvectors)"\n');

print('* * * E X A M * * *');
# 4x4 matrix. Since the s value has to be (at some extent) carefuly chosen
# this will not be a random matrix
A = [[0., 2., 2., 8.],
     [2., 4., 0., 9.],
     [2., 0., 1., 7.],
     [1., 9., 3., 2.]];

print('Matrix used fort this exercise:');
print(A);

# linalg used to compare the results
vals, vect = np.linalg.eig(A);

print('\nEigenvalues obtained using numpy.linalg.eig:')
print(vals);

print('\nEigenvectors obtained using numpy.linalg.eig:')
print(vect);

s = 3.0; # Estimated value for the eigenvalue
print('\nWe will aim for eigenvalue equal to %g. Therefore, s will be %g.' % (vals[3], s));
print('This can be changed by making s = 12.0, s = -5.0 or s = -1.0 for instance.\n');

###   INVERSE ITERATION METHOD    ###
print('* * * S O L U T I O N * * *');
inv_it_eigenval, inv_it_eigenvect = inverse_iteration(A, s);

print('Looking for the eigenvalue (and eigenvector) closest to: ', s);
print('Eigenvalue expected: ', vals[3]);
print('Eigenvalue calculated: ', inv_it_eigenval);

print('\nEigenvector expected: ', vect[:, 3]);
print('Eigenvector calculated*: ', inv_it_eigenvect);
print('\n*The difference in the sign, if consistent for the rest');
print('of eigenvectors, does not make the result to be wrong.');
print('PS: it is.');

print('\n Guillermo Garrido Hernández. June 6th 2019.');
