a = int(input('first number: '))
b = int(input('second number: '))
c = int(input('1: addition, 2: subtraction, 3: multiplication, 4: division \n'))
if (c == 1):
    print('sum: ',(a+b))
elif(c == 2):
    print('difference: ',(a-b))
elif(c == 3):
    print('product: ',(a*b))
elif(c == 4):
    print('quotient: ',(a/b))
else:
    print('invalid')
