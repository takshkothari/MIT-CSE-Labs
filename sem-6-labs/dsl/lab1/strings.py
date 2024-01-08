# 1. Updating a string
var1 = 'Hello World!'
print ("Updated String :", var1[:6] + 'Python')
# Ans: Updated String :Hello Python

# 2. String formatting operator
print( "My name is %s and weight is %d kg!" % ('Abay', 55))
# My name is Abay and weight is 55 kg!

# 3. Built−in String methods

# capitalize() , the first character of the string is converted to upper case.
str = "this is string example wow!!!";
print (str.capitalize())
# Ans: This is string example wow!!!

# count(), counts the number of times a specific ‘substring’, occurrence in the main string
str = "this is string example ... wow!!!";
str.count('s')
# Ans: 3
# three times‘s’, appears in str.

# find() , will locate the position of searching ‘substring’, (index)
str.find('example')
# Ans: 15
#at 15 th index, the substring ‘example’ is placed.

# lower(),returns a copy of the string in which all case−based characters have been lowercased.
str = "THIS IS STRING EXAMPLE ... WOW!!!";
print (str.lower())
# this is string example... wow!!!

# replace(), this method returns a copy of the string with all occurrences of substring old replaced by new.
str = "this is string example ... wow!!! this is really string";
print (str.replace("is", "was"))
# Ans: thwas was string example ... wow!!! thwas was really string

# swapcase(), this method returns a copy of the string in which al l the case−based characters have had their case swapped.
str = "this is string example ... wow!!!";
print (str.swapcase())
# Ans: THIS IS STRING EXAMPLE ... WOW!!!"

# title(),returns a copy of the string in which first characters of all the words are capitalized.
str = "this is string example ... wow!!!";
print (str.title())
# Ans: This Is String Example ... Wow!!!