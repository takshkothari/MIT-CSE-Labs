lst = [1, -2, 3, -4, 5, -6, 7, -8]
i = 0
while i < len(lst):
    if lst[i] < 0:
        print(lst[i])
    i += 1
else:
    print("Loop completed successfully.")