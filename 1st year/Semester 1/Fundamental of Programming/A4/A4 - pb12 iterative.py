""""
Consider the natural number n (n<=10) and the natural numbers a1, ..., an. \
Determine all the possibilities to insert between all numbers a1, ..., an the operators +
and – such that by evaluating the expression the result is positive.

For the solution:
1. Generate all possibilities
2. Check if the result is actually positive or not
3. If 2) is being checked, then print the expression

We create an array of 0 and 1, 0 meaning + and 1 meaning - of length len(array)-1
"""

import random

def Generate_List_Of_Random_Numbers(arraylength):
    List_Of_Random_Numbers = []

    for i in range(0, arraylength):
        List_Of_Random_Numbers.append(random.randint(0, 100))

    return List_Of_Random_Numbers

def check_if_the_number_of_signs_that_are_in_between_of_our_expression_is_max(array, sign_array):
    if (len(sign_array) == len(array)-1):
        return True
    else:
        return False

def checking_whether_the_expression_is_positive_or_not(array, sign_array):
    sum_of_expression = array[0]

    for i in range (0, len(sign_array)):
        if (sign_array[i] == 0):
            sum_of_expression = sum_of_expression + array[i + 1]

        else:
            sum_of_expression = sum_of_expression - array[i + 1]

    if (sum_of_expression >= 0):
        return True
    else:
        return False


def print_the_valid_expression(array, sign_array):
    print("A valid expression is:")
    for i in range (0, len(sign_array)):
        if (sign_array[i] == 0):
            print(array[i], " + ")

        else:
            print(array[i], " - ")

    print(array[len(array) - 1])
    print()


def iterative_backtracking(array, sign_array):
    for position_in_expression in range (0, len(array)-1):

        for index in range(position_in_expression + 1, len(array)-1):

            if (check_if_the_number_of_signs_that_are_in_between_of_our_expression_is_max(array, sign_array)):

                if (checking_whether_the_expression_is_positive_or_not(array, sign_array)):
                    print_the_valid_expression(array, sign_array)

                if(sign_array[len(sign_array)-1] == 0):
                    sign_array.pop(len(sign_array)-1)
                    sign_array.append(1)
                    if (checking_whether_the_expression_is_positive_or_not(array, sign_array)):
                        print_the_valid_expression(array, sign_array)

                if (sign_array[len(sign_array)-1] == 1):
                    while (sign_array[len(sign_array)-1] == 1):
                        sign_array.pop(len(sign_array)-1)
                        index = index - 1

                    sign_array.pop(index)
                    sign_array.append(1)

            else:
                sign_array.append(0)






def Menu():
    while True:
        print()
        print("Generate a list of random natural numbers.")
        array = []
        print("The length of the initial array will be equal to:")
        arraylength = int(input())

        if (arraylength <= 0 or arraylength > 10):
            while(arraylength <= 0 or arraylength > 10):
                print("The array cannot be generated, due to the length being a negative number."
                    "Please introduce a different value:")
                arraylength = int(input())

        array = Generate_List_Of_Random_Numbers(arraylength)
        print(array)
        print()

        sign_array = [0] * (len(array) - 1)
        print()

        iterative_backtracking(array, sign_array)


def main_program():
    Menu()

main_program()
