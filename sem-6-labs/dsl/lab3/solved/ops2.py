import numpy as np

# Stacking together different arrays
A1=np.array([(3,4,5),(12,6,1)])
A2=np.array([(1,2,6),(-4,3,8)])
D1=np.vstack((A1,A2))
print(D1)
# 3 4 5
# 12 6 1
# 1 2 6
# -4 3 8

D2=np.hstack((A1,A2))
print(D2)
# 3 4 5 1 2 6
# 12 6 1 -4 3 8

# Stacking 1-D array into 2-D array (column wise)
a = np.array([4.,2.])
b = np.array([3.,8.])
print(np.column_stack((a,b))) # returns a 2D array
# array([[ 4., 3.], [ 2., 8.]])
print(np.hstack((a,b))) # array([ 4., 2., 3., 8.])

# Indexing with array of indices

a = np.arange(12)**2# the first 12 square numbers
i = np.array( [ 1,1,3,8,5 ] )# an array of indices
print(a[i]) # the elements of a at the positions i
# array([ 1, 1, 9, 64, 25])

j = np.array( [ [ 3, 4], [ 9, 7 ] ] ) # a bidimensional array of indices
print(a[j]) # the same shape as j
# array([[ 9, 16], [81, 49]])

# Usage of for-loop (Mapping by Value)
# Calculate sum of all the elements in a 2D Numpy Array (iterate over elements)
a=np.array([(3,2,9),(1,6,7)])
s1=0
for row in a:
    for col in row:
        s1+=col
print(s1)

# Usage of for-loop (Mapping by Index)
# Calculate sum of all the elements in a 2D Numpy Array (iterate over range)
a=np.array([(3,2,9),(1,6,7)])
s=0
for i in range(a.shape[0]):
    for j in range(a.shape[1]):
        s+=a[i,j]
print(s)
