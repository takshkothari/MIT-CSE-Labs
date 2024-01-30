class q3:
	def power(self, x, n):
		return x**n

a, b = map(int, input("enter the base and exponent: ").strip().split())
print(q3().power(a, b))