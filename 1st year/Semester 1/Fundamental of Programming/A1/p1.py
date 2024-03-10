"""Solve the problem from the first set here"""
"""Generate the first prime number larger than a given natural number n."""

import math
def ifNumberBiggerThanNisPrime (NumberBiggerThanN : int):
#this function checks whether the NumberBiggerThanN is actually prime
#NumberBiggerThanN will be the minimal prime number greater than given n
    #particular cases - 0 or 1 that are not prime; and 2 or 3 that are
    if (NumberBiggerThanN <= 1) :
        return False
    if (NumberBiggerThanN <= 3) :
        return True

    if (NumberBiggerThanN % 2 == 0) :
        return False #even numbers, except 2, case we already veriffied, are not prime
    if (NumberBiggerThanN % 3 == 0) :
        return False #numbers that are divisible with 3 are also not prime

    for possibledivisor in range (5,int(math.sqrt(NumberBiggerThanN) + 1), 6):
    #we start the range from 5, because if the number is divisible with 4, it should have been divisible with 2 as well - case already verified
    #we add 2, so we check only the odd possible divisors of the NumberBiggerThanN
        if (NumberBiggerThanN != 5):
            if (NumberBiggerThanN % possibledivisor == 0):
                return False

    return True

def NextPrimeNumberBiggerThanN (initialnumber : int):
#this function returns the NumberBiggerThanN = the smallest prime number greater than N
    if (initialnumber <= 1):
        return 2

    NumberBiggerThanNtoVerify = initialnumber + 1 #we start by verifing if the next number, bigger than n, is prime
    stopbecausewefoundtheprime = False
#this while loop stops when the boolean stopbecausefoundtheprime becomes true due to finding the next prime number greater than n
    while (not stopbecausewefoundtheprime):
        if(ifNumberBiggerThanNisPrime(NumberBiggerThanNtoVerify)):
            stopbecausewefoundtheprime = True

        else:
            NumberBiggerThanNtoVerify+=1

    return NumberBiggerThanNtoVerify

n = int(input("Write down the natural number n:"))
print("Next prime number greater than n is: ")
print(NextPrimeNumberBiggerThanN(n))