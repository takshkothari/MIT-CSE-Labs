class q2:
	def q2(self, arr, key):
		for i in range(0, len(arr)):
			for j in range(i+1, len(arr)):
				if arr[i] + arr[j] == key:
					print(i+1, j+1, "\n")

n = int(input("enter number of elements : "))
arr = list(map(int, input("\nenter the numbers: ").strip().split()))[:n]
key = int(input("enter target value : "))

q2().q2(arr, key)