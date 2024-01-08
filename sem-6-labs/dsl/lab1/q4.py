x = int(input('Enter number 1: '))
y = int(input('Enter number 2: '))
z = int(input('Enter number 3: '))

if x > y and x > z:
    print(x)
elif y > x and y > z:
    print(y)
else:
    print(z)