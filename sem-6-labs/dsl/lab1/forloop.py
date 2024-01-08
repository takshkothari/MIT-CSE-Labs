# Eg.1
for val in [5,4,3,2,1]:
    print(val)
print ('Done')

# Eg.2
stud=['Ram','Vijay','Nithya','Anu','Ramesh','suja']
for k in stud:
    print('Hello:', k)
print('done')

# Eg.3
for i in range(5):
    print(i)
    if i>2:
        print('Bigger than 2')
    print('Done with i',i)

# Eg.4: Calculate factors of a number
x=int(input('Enter a number:'))
for i in range(1,x+1):
    if x%i ==0:
        print(i)
x=10
1,2,5,10

# Eg.5: Calculate largest number in an array
from math import *
x= [9, 41, 12, 3, 74, 15]
Largest= -inf
for i in x:
    if i>Largest:
        Largest=i
print(Largest)

# Eg.6: Calculate smallest number in an array
from math import *
x= [9, 41, 12, 3, 74, 15]
smallest=inf
for i in x:
    if i<smallest:
        smallest=i
print(smallest)

# Eg.7: Calculate the count, sum and average of numerical array
x= [9, 41, 12, 3, 74, 15]
count=sum=avg=0
for i in x:
    count=count+1
    sum=sum+i
avg=sum/count
print(count)
print(sum)
print(avg)

# Eg.8: Filtering in a loop (print all numbers >20)
x= [9, 41, 12, 3, 74, 15]
for i in x:
    if i>20:
        print (i)

# Eg.9: For the above problem, instead of printing the result, store the elements in a
# variable (object)
x= [9, 41, 12, 3, 74, 15]
res=[]
for i in x:
    if i>20:
        res.append(i)

# Eg.10: For the above x, replace all elements <20 into zero. Store the result in different
# variable (object)
import numpy as np
y=np.zeros(len(x))
for i in range(len(x)):
    if x[i]>20:
        y[i]=x[i]
print(y)

# Eg. 11: Program using elif to check more than one condition.
price = 100
if price > 100:
    print("price is greater than 100")
elif price == 100:
    print("price is 100")
elif price < 100:
    print("price is less than 100")

# Eg. 12: Program using while loop -
# program to display numbers from 1 to 5
# initialize the variable
i = 1
n = 5
# while loop from i = 1 to 5
while i <= n:
    print(i)
i = i + 1

# Eg. 13:Take input from user , until user enters zero and calculate the sum of entered numbers.
total = 0
number = int(input('Enter a number: '))
# add numbers until number is zero
while number != 0:
    total += number # total = total + number
# take integer input again
number = int(input('Enter a number: '))
print('total =', total)