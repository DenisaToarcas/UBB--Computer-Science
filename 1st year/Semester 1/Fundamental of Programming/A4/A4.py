"""
    The sequence a = a1, ..., an with distinct integer numbers is given.
Determine all subsets of elements having the sum divisible by a given n.
"""

import random

def print_the_subset(subset, divisor):
    print()
    print("A subset which has the sum divisible with ", divisor, "is:")
    for i in range(0, len(subset)):
        if (subset[i] != 0):
            print(subset[i])

def GenerateListOfNRandomNumbers(arraylength):
    ListOfRandomNo = []
    for i in range(0, arraylength):
        ListOfRandomNo.append(random.randint(0, 100))
    return ListOfRandomNo

def generate_subsets(array, arraylength, position, sum_until_now, divisor, subset : list, subset_length):
        if (sum_until_now % divisor == 0):
            subset[subset_length] = array[position]
            print_the_subset(subset, subset_length)
            subset_length = subset_length + 1

        #se futizeaza in momentul in care incerc sa revin sa creez un nou subset mai mic decat anteriorul

        for i in range (position + 1, arraylength):
            generate_subsets(array, arraylength, i, sum_until_now + array[i], divisor, subset, subset_length)


def Menu():
    print()
    print("Generate a list of random natural numbers.")
    array = []
    print("The length of the initial array will be equal to:")
    arraylength = int(input())

    if (arraylength <= 0):
        while(arraylength <= 0):
            print("The array cannot be generated, due to the length being a negative number."
                "Please introduce a different value:")
            arraylength = int(input())

    array = GenerateListOfNRandomNumbers(arraylength)
    print(array)
    print()

    print("Introduce the number with which the sum of all generated subsets may be divisible:")
    divisor = int(input())

    if (divisor == 0):
        while(divisor == 0):
            print("We cannot divide any number by 0."
                "Please introduce a different value for the divisor:")
            divisor = int(input())


    for i in range(0, arraylength):
        position = i
        subset_length = 0
        subset = [0] * (len(array)-1)
        sum_until_now = array[i]
        generate_subsets(array, arraylength, position, sum_until_now, divisor, subset, subset_length)


Menu()