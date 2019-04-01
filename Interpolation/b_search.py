import sympy as sy
import numpy as np

def half_int(n, x, z):
    # n is the dimension of the list X
    # Z is a point in betweet the first and last element of the list X
    it = int(0); # iteration number
    L = int (0); # Control for the list's length
    R = int(n-1);

    if (L > R):
        print("The List used does not have length larger than zero. Fix this and try again.\n");
        return -1;

    while (L <= R):
        # Search for the interval (elements of X) in which Z belongs
        m = int((L+R)/2);
        if (x[m] <= z and x[m+1] > z):
            return m;
        elif (x[m] < z):
            L = m + 1;
        elif (x[m] > z):
            R = m - 1;
        it = it + 1;
        if (it > n):
            print("Search not succesful.\n");
            return -1;
            break;
