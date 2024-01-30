class subs:
	def ssets(self, sset):
		return self.subsetsRecur([], sorted(sset))

	def subsetsRecur(self, current, sset):
		if sset:
			return self.subsetsRecur(current, sset[1:]) + self.subsetsRecur(current + [sset[0]], sset[1:])
		return [current]

n = int(input("enter number of elements : "))
arr = list(map(int, input("\nenter the numbers: ").strip().split()))[:n]
print(subs().ssets(arr))