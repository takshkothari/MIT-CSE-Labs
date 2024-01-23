def binary_search(arr, l, h, x):
    if h >= l:
        m = (h + l) // 2
        if arr[m] == x:
            return m
        elif arr[m] > x:
            return binary_search(arr, l, m - 1, x)
        else:
            return binary_search(arr, m + 1, h, x)
    else:
        return -1

n = int(input("enter number of elements : "))
arr = list(map(int, input("\nenter the numbers: ").strip().split()))[:n]
x = int(input('enter number to be searched: '))

result = binary_search(arr, 0, len(arr)-1, x)

if result != -1:
    print("present at index ", str(result))
else:
    print("not present")