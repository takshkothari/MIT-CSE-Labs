class Human:
	species = "H. sapiens"

	def __init__(self, name):
		self.name = name
		self.age = __package__

	def say(self, msg):
		print("{name}: {message}".format(name=self.name, message=msg))

	def sing(self):
		return 'yo... yo... microphone check... one two... one two...'
	
	def get_species(cls):
		return cls.species
	
	def grunt():
		return "*grunt*"
	
	def age(self):
		return self._age
	
	def age(self, age):
		self._age = age

	def age(self):
		del self._age

if __name__ == '__main__':
	i = Human(name="Ian")
	i.say("hi")
	j = Human("Joel")
	j.say("hello")
	i.say(i.get_species())
	Human.species = "H. neanderthalensis"
	i.say(i.get_species())
	j.say(j.get_species())
	print(Human.grunt())
	print(i.grunt())

	i.age = 42
	i.say(i.age)
	j.say(j.age)
	del i.age
