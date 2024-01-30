class q3:
	def power(self, base, exp):
		res = 1
		for i in range(exp):
			res = res * base
		return res

a, b = map(int, input("enter the base and exponent: ").strip().split())
print(q3().power(a, b))