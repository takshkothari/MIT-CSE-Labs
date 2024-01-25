import numpy as np

ar = [1, 2, 3, 4, 5]
arr = np.array(ar, dtype=float)
print(arr)

t = (6, 7, 8, 9, 10)
arr2 = np.array(t)
print(arr2)

z = np.zeros((3, 4))
print(z)

print(np.arange(0, 20, 5))

z = z.reshape(2, 2, 3)
print(z)

a = np.array([[1, 2],
              [3, 4]])

print(np.max(a)) # max
print(np.min(a)) # min

print(np.max(a, axis=1)) # row max
print(np.min(a, axis=1)) # row min

print(np.max(a, axis=0)) # col max
print(np.min(a, axis=0)) # col min

print(np.sum(a))
print(np.sum(a, axis=0)) # col sum
print(np.sum(a, axis=1)) # row sum

b = a.T
print(b) # transpose

print(a+b) # sum
print(a*b) # element wise product