# Solve the problem from the third set here
"""Generate the largest perfect number smaller than a given natural number n. If such a number does not exist, a message should be displayed. A number is perfect if it is equal to the sum of its divisors, except itself. (e.g. 6 is a perfect number, as 6=1+2+3)."""

def sumofthedivisorsofthenumber (givennumber : int):
	sumofthedivisors = 1
	for possibledivisor in range (2, givennumber-1, 1):
		if (givennumber % possibledivisor == 0):
			sumofthedivisors += possibledivisor
	return sumofthedivisors

def isperfectornot (numberwearechecking : int):
	contorforperfect = False
	if (sumofthedivisorsofthenumber(numberwearechecking) == numberwearechecking):
		contorforperfect = True
	return contorforperfect

def lookingfortheperfectnumbersmallerthanN (numberwrittenonthekeyboard : int):
	numbersmallerthanN = numberwrittenonthekeyboard - 1
	while (isperfectornot(numbersmallerthanN) == False and numbersmallerthanN != 0):
			numbersmallerthanN = numbersmallerthanN - 1
	return numbersmallerthanN



n = int(input("Write down the given n:"))
if (lookingfortheperfectnumbersmallerthanN(n) == 0):
	print("There is no perfect number smaller than n")
else:
	print("The perfect number smaller than n is:")
	print(lookingfortheperfectnumbersmallerthanN(n))
