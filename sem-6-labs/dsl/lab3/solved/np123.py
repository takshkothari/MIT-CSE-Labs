import numpy as np

# 1. Array creation
A = np.array ([2,5,10])
print(A.dtype) # Will show, int64 data type
B=np.array ([2.4,10.6,5.2])
print(B.dtype) # Will show, float64 data type

# Creating sequence of sequence will create 2-dimensional array.
A=np.array([(3,4,5),(12,6,1)])
print(A)
Z=np.zeros((2,4)) # will create zero matrix of dimension 2x4
print(Z)
# Similarly, np.ones((3,3)) will create one’s matrix of dimension 3x3

# To create a sequence of data,
S=np.arange(10,30,5)
print(S) # will give (10,15,20,25,30), with step size of 5

x = np.arange( 0, 2, 0.3 ) # it accepts float arguments
print(x) # array([ 0. , 0.3, 0.6, 0.9, 1.2, 1.5, 1.8])

#lnstead of step-size, we can specify total number of elements in the array using
S1=np.linspace(0,2,9) # produce 9 numbers starting 0 & ends with 2array([ 0. , 0.25, 0.5 , 0.75, 1. , 1.25, 1.5 , 1.75, 2. ])
print(S1)

#usage of Random Number functions
import random
print(random.choice([1,2,3,4,5])) # this will pick one number from the list randomly
print(random.choice('python')) # will pick one character from the string randomly
print(random.randrange(25,50)) # will pick one integer between 25 to 50
print(random.randrange(25,50,2)) # will pick one integer between 25 to 50 with step size of 2
print(random.random()) # will pick a random number between 0 to 1
print(random.uniform(5,10)) # will pick a floating point number between 5 to 10
random.shuffle([1,2,3,4,5]) # will shuffle the list elements
random.seed(10) # to get same random value during every execution

# 2- Dimensional array (Matrix)

a = np.arange(15).reshape(3, 5)
# array([[ 0, 1, 2, 3, 4],
# [ 5, 6, 7, 8, 9],
# [10, 11, 12, 13, 14]])
#to check the dimension
print(a.shape) # (3,5)
a.size # will return total elements in matrix (here 15)

# to transpose a matrix
print(a.T) # transposed to 5x3 matrix

# 3- Dimensional array
c = np.arange(24).reshape(2,3,4) # 1 st value indicates (no of planes) (3,4) is the dimensionprint(c)
# [[[ 0 1 2 3]
# [ 4 5 6 7]
# [ 8 9 10 11]]
# [[12 13 14 15]
# [16 17 18 19]
# [20 21 22 23]]]
print(c.shape) # will return (2,3,4)
print(c[1,...]) # is equal to c[1,:,:] # will fetch all elements of 2 nd plane
print(c[...,2]) # is equal to c[:,:,2] [[3,7,11],[15,19,23]]