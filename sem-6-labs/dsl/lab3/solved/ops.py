import numpy as np

# Array operations

a = np.array( [20,30,40,50] )
b = np.arange( 4 )
print(b) # array([0, 1, 2, 3])
c = a-b
print(c) # array([20, 29, 38, 47])
print(b**2) # array([0, 1, 4, 9])
print(10*np.sin(a)) # array([ 9.12945251, -9.88031624, 7.4511316 , -2.62374854])
print(a<35) # array([ True, True, False, False], dtype=bool)

# Matrix operations

A = np.array( [[1,1],[0,1]] )
B = np.array( [[2,0],[3,4]] )
print(A*B)
# elementwise product -> array([[2, 0], [0, 4]])

print(A.dot(B)) # (OR) np.dot(A, B)
# matrix product -> array([[5, 4], [3, 4]])

b = np.arange(12).reshape(3,4)
print(b) # array([[ 0, 1, 2, 3], [ 4, 5, 6, 7], [ 8, 9, 10, 11]])
print(b.sum(axis=0)) # array([12, 15, 18, 21]) # sum of each column
print(b.sum(axis=1)) # array([6, 22, 38]) # sum of each row

# Indexing, Slicing & Iterating Array

a = np.arange(10)**3
print(a) # array([ 0, 1, 8, 27, 64, 125, 216, 343, 512, 729])
print(a[2:5]) # array([ 8, 27, 64])
print(a[0:7:2]) # array([0,8,64,216])

# Let ‘b’, is an input matrix of size 5x4
b = np.array([[ 0, 1, 2, 3],
              [10, 11, 12, 13],
              [20, 21, 22, 23],
              [30, 31, 32, 33],
              [40, 41, 42, 43]])

print(b[2,3]) #will fetch 23
print(b[0:5,1]) # or b[:5,1] or b[:,1] #will fetch [1,11,21,31,41]
print(b[-1,:]) # will fetch last row
print(b[:,-1]) # will fetch last col

for row in b:
    print(row) # will print every row
    
for element in b.flat:
    print(element) # will show all elements of b in 1−D array

# Changing the shape of a matrix
    
print(b.ravel()) # returns the array flattened to (1x 20)
# Later, we can convert 5x4 matrix into 4x 5 matrix using
B1=b.reshape(4,5)
print(B1)