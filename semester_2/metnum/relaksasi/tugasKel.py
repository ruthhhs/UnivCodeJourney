# Function for Solving System of Equations 
# using Successive Over-relaxation
# Venki Uddameri

# import libraries
import numpy as np

# define function
# M is the coeff matrix; b is RHS matrix, x is the initial guesses
# tol is acceptable tolerance and Nmax = max. iterations

def sor(M,b,x,w,tol,Nmax):
    N = len(M)  # length of the coefficient matrix
    C = np.zeros((N,N)) # initialize iteration coeff matrix
    d = np.zeros(N) # initiation iteration RHS matrix
    # Create iteration matrix
    for i in np.arange(0,N,1):
        pvt = M[i,i]  # identify the pivot element
        C[i,:] = -M[i,:]/pvt # divide coefficient by pivot
        C[i,i] = 0 # element the pivot element
        d[i] = b[i]/pvt # divide RHS by Pivot element
        
    # Perform iterations
    res = 100 # create a high res so there is at least 1 iteration
    iter = 0 #initialize iteration
    xold = x # initialize xold
    # iterate when residual > tol or iter <= max iterations
    while(res > tol and iter <= Nmax):
        for i in np.arange(0,N,1):  # loop through all unknowns
            x[i] = (1-w)*xold[i] + w*(d[i] + sum(C[i,:]*x)) # estimate new values
        res = np.sum(np.abs(np.matmul(M,x) - b)) # compute res
        iter = iter + 1 # update residual
        xold = x
    return(x)

# Solve Example
Nmax = 100  # Max. Number of iteration
tol = 1e-03 # Absolute tolerance
M = [[3,2],[-1,1]]
M = np.array(M) # Coefficient Matrix
b = [50, 35] 
b = np.array(b) # RHS matrix
y = [0,0] 
y = np.array(y) # Initial Guesses
w = 1.25
X = sor(M,b,y,w,tol,Nmax) # Apply the function
print(X)