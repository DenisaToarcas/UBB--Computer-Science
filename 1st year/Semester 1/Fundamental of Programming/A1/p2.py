# Solve the problem from the second set here
"""The palindrome of a number is the number obtained by reversing the order of its digits (e.g. the palindrome of 237 is 732). For a given natural number n, determine its palindrome."""

#the function called TakeTheLastDigitOfTheNumber gets the unit of the number
#it verifies if the number which it is working with is formed out of several digits or not
#in case of the number being formed out with only 1 digit, it returns the number itself
def TakeTheLastDigitOfTheNumber(numberwearetakingoutthedfigitsfrom : int):
    if (numberwearetakingoutthedfigitsfrom // 10 != 0):
        return numberwearetakingoutthedfigitsfrom % 10
    else:
        return numberwearetakingoutthedfigitsfrom

#the second function, called ConstructThePalindromeOfTheGivenNumber returns the palindrome created out with the digits contained by the number
#it works out the reverse in base 10
def ConstructThePalindromeOfTheGivenNumber (initialnumberwrittenonthekey : int):
    PalindromeCreatedOutOfTheDigitsIncludedIntheGivenNumber = 0
    if (initialnumberwrittenonthekey // 10 != 0):
     while (initialnumberwrittenonthekey != 0):
        PalindromeCreatedOutOfTheDigitsIncludedIntheGivenNumber = PalindromeCreatedOutOfTheDigitsIncludedIntheGivenNumber*10 + TakeTheLastDigitOfTheNumber(initialnumberwrittenonthekey)
        initialnumberwrittenonthekey = initialnumberwrittenonthekey//10
    else: PalindromeCreatedOutOfTheDigitsIncludedIntheGivenNumber = initialnumberwrittenonthekey

    return PalindromeCreatedOutOfTheDigitsIncludedIntheGivenNumber


n = int(input("Write down the given n:"))
print("The palindrome associated to n is:")
print(ConstructThePalindromeOfTheGivenNumber(n))



