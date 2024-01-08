p = 0
n = 0

l = [11, -21, 0, 45, 66, -93]
for i in l:
    if i < 0:
        n = n + 1
    elif i > 0:
        p = p + 1

print("positive - ", p)
print("negative - ", n)