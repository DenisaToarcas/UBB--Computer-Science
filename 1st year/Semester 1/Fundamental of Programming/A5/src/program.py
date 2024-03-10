"""

Problem Statement

Implement a menu-driven console application that provides the following functionalities:

    1.Read a list of complex numbers (in z = a + bi form) from the console.

    2.Display the entire list of numbers on the console.

    3.Display on the console the sequence, subarray or numbers required by the properties that were assigned to you.
    Each student will receive one property from Set A and another one from Set B.

    Property from Set A:
        1.Length and elements of a longest subarray of distinct numbers.

    Property of Set B:
        9.The length and elements of a longest increasing subsequence, when considering each number's modulus

    4.Exit the application.


"""
import math
import random
import cmath

#
# Write the implementation for A5 in this file
#

#
# Write below this comment
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
def create_the_complex_number_list_representation(real_part: int, imaginary_part: int):
    """
    Creates a new complex number

    :return: The new complex number
    """
    return [real_part, imaginary_part]


def get_the_real_part_of_the_complex_number_list_representation(complex_number):
    return complex_number[0]


def get_the_imaginary_part_of_the_complex_number_list_representation(complex_number):
    return complex_number[1]


def transform_into_string_the_list_representation_of_the_complex_number(complex_number):
    """
    Returns the str representation of the complex number
    :param complex_number: Given complex_number
    :return: a string
    """

    return str(complex_number[0]) + " + " + str(complex_number[1]) + "i"


#
# Write below this comment
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def create_the_complex_number_dictionary_representation(real_part: int, imaginary_part: int):
    """
    Creates a new complex number

    :return: The new complex number
    """
    return {
        "real_part": real_part,
        "imaginary_part": imaginary_part
    }


def get_the_real_part_of_the_complex_number_dictionary_representation(complex_number):
    return complex_number.get("real_part")


def get_the_imaginary_part_of_the_complex_number_dictionary_representation(complex_number):
    return complex_number.get("imaginary_part")


def transform_into_string_the_dictionary_representation_of_the_complex_number(complex_number):
    """
    Returns the str representation of the complex number
    :param complex_number: Given complex_number
    :return: a string
    """

    return str(complex_number.get("real_part")) + " + " + str(complex_number.get("imaginary_part")) + "i"


#
# Write below this comment
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def generate_complex_number_list_representation():
    list_representation_of_complex_numbers = []

    for i in range(0, 10):
        real_part = random.randint(0, 100)
        imaginary_part = random.randint(0, 100)

        complex_number = create_the_complex_number_list_representation(real_part, imaginary_part)
        list_representation_of_complex_numbers.append(complex_number)

    return list_representation_of_complex_numbers


def generate_complex_number_dictionary_representation(list_representation_of_complex_numbers):
    dictionary_representation_of_complex_numbers = []

    for i in range(0, 10):
        complex_number = create_the_complex_number_dictionary_representation(
            get_the_real_part_of_the_complex_number_list_representation(
                list_representation_of_complex_numbers[i]),
            get_the_imaginary_part_of_the_complex_number_list_representation(
                list_representation_of_complex_numbers[i]))
        dictionary_representation_of_complex_numbers.append(complex_number)

    return dictionary_representation_of_complex_numbers


def if_this_complex_number_is_a_duplicate_of_another_one_in_the_subsequence(list_representation_of_complex_numbers,
                                                                            found_in_the_list_of_complex_numbers_real_part,
                                                                            found_in_the_list_of_complex_numbers_imaginary_part):
    for i in range(0, len(found_in_the_list_of_complex_numbers_real_part)):
        if (found_in_the_list_of_complex_numbers_real_part[
            get_the_real_part_of_the_complex_number_list_representation(
                list_representation_of_complex_numbers[i])] == 1 and
                found_in_the_list_of_complex_numbers_imaginary_part[
                    get_the_imaginary_part_of_the_complex_number_list_representation(
                        list_representation_of_complex_numbers[i])] == 1):
            return True
        else:
            return False


def find_the_longest_subarray_of_distinct_complex_numbers(list_representation_of_complex_numbers):

    found_in_the_list_of_complex_numbers_real_part = []
    found_in_the_list_of_complex_numbers_imaginary_part = []
    maximum_length_of_a_subarray = 0
    starting_position_of_the_subarray = 0
    ending_position_of_the_subarray = 0

    found_in_the_list_of_complex_numbers_real_part = [0] * 101
    found_in_the_list_of_complex_numbers_imaginary_part = [0] * 101

    for i in range(0, len(list_representation_of_complex_numbers)):

        found_in_the_list_of_complex_numbers_real_part[
            get_the_real_part_of_the_complex_number_list_representation(list_representation_of_complex_numbers[i])] = 0

        found_in_the_list_of_complex_numbers_imaginary_part[
            get_the_imaginary_part_of_the_complex_number_list_representation(
                list_representation_of_complex_numbers[i])] = 0

    for i in range(0, len(list_representation_of_complex_numbers)):


        found_in_the_list_of_complex_numbers_real_part[
            get_the_real_part_of_the_complex_number_list_representation(list_representation_of_complex_numbers[i])] = 1

        found_in_the_list_of_complex_numbers_imaginary_part[
            get_the_imaginary_part_of_the_complex_number_list_representation(
                list_representation_of_complex_numbers[i])] = 1

        for j in range(i + 1, len(list_representation_of_complex_numbers)):
            if (if_this_complex_number_is_a_duplicate_of_another_one_in_the_subsequence(
                    list_representation_of_complex_numbers,
                    found_in_the_list_of_complex_numbers_real_part,
                    found_in_the_list_of_complex_numbers_imaginary_part) == True):
                if (j - i + 1 > maximum_length_of_a_subarray):
                    maximum_length_of_a_subarray = j - i + 1
                    starting_position_of_the_subarray = i
                    ending_position_of_the_subarray = j

            else:
                found_in_the_list_of_complex_numbers_real_part[
                    get_the_real_part_of_the_complex_number_list_representation(
                        list_representation_of_complex_numbers[i])] = 1

                found_in_the_list_of_complex_numbers_imaginary_part[
                    get_the_imaginary_part_of_the_complex_number_list_representation(
                        list_representation_of_complex_numbers[i])] = 1

        for j in range(0, len(list_representation_of_complex_numbers)):
            found_in_the_list_of_complex_numbers_real_part[
                get_the_real_part_of_the_complex_number_list_representation(
                    list_representation_of_complex_numbers[i])] = 0

            found_in_the_list_of_complex_numbers_imaginary_part[
                get_the_imaginary_part_of_the_complex_number_list_representation(
                    list_representation_of_complex_numbers[i])] = 0

    return [maximum_length_of_a_subarray, starting_position_of_the_subarray, ending_position_of_the_subarray]

def get_modulus_of_complex_number(complex_number):

    real_part = get_the_real_part_of_the_complex_number_list_representation(complex_number)
    imaginary_part = get_the_imaginary_part_of_the_complex_number_list_representation(complex_number)

    return math.sqrt(real_part*real_part + imaginary_part*imaginary_part)
def position_where_we_should_place_the_complex_number(increasingSequence, left, right, complex_number):

    while (right - left > 1):

        middle_point = left + (right - left) // 2

        if (get_modulus_of_complex_number(increasingSequence[middle_point])
                >= get_modulus_of_complex_number(complex_number)):
            right = middle_point
        else:
            left = middle_point

    return right

def find_longest_increasing_subsequence(list_representation_of_complex_numbers):
    increasingSubsequence = []

    increasingSubsequence.append(list_representation_of_complex_numbers[0])

    for i in range(1, len(list_representation_of_complex_numbers)):
        if (get_modulus_of_complex_number(list_representation_of_complex_numbers[i]) <
        get_modulus_of_complex_number(increasingSubsequence[0])):
            increasingSubsequence[0] = list_representation_of_complex_numbers[0]
            #   if the modulus of the element in list is smaller than the modulus of the first element in the
            #increasing subsequence, that means that there starts a new increasing subsequence

        elif (get_modulus_of_complex_number(list_representation_of_complex_numbers[i]) >
        get_modulus_of_complex_number(increasingSubsequence[len(increasingSubsequence) - 1])):
            increasingSubsequence.append(list_representation_of_complex_numbers[i])
            #   else if the modulus of the element in list is greater than the modulus of the last element the increasing
            #subsequence that means that this element will be contained in this subsequence

        else:
            increasingSubsequence[position_where_we_should_place_the_complex_number(increasingSubsequence, -1, len(increasingSubsequence) - 1,
                                                                                    list_representation_of_complex_numbers[i])] = \
                list_representation_of_complex_numbers[i]
            #   else we binary search for the position where the element will be placed, in order to maintain
            #the sequence increasing

    return increasingSubsequence


#
# Write below this comment
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
#

def print_the_list_of_complex_numbers_list_representation(list_representation_of_complex_numbers):
    for i in range(0, len(list_representation_of_complex_numbers)):
        print(i + 1, ")", transform_into_string_the_list_representation_of_the_complex_number(
            list_representation_of_complex_numbers[i]))


def print_the_list_of_complex_numbers_dictionary_representation(dictionary_representation_of_complex_numbers):
    for i in range(0, len(dictionary_representation_of_complex_numbers)):
        print(i + 1, ") {", transform_into_string_the_dictionary_representation_of_the_complex_number(
            dictionary_representation_of_complex_numbers[i]), "}")


def read_a_list_of_complex_numbers(list_representation_of_complex_numbers, dictionary_representation_of_complex_numbers):
    how_many_complex_numbers_do_you_want_to_introduce = int(
        input("How many complex numbers would you like to store in memory:"))

    for i in range(0, how_many_complex_numbers_do_you_want_to_introduce):
        print()
        real_part = int(input("real part of the complex number:"))
        imaginary_part = int(input("imaginary part of the complex number:"))

        list_representation_of_complex_numbers.append(
            create_the_complex_number_list_representation(real_part, imaginary_part))

        dictionary_representation_of_complex_numbers.append(
            create_the_complex_number_dictionary_representation(real_part, imaginary_part))

    return how_many_complex_numbers_do_you_want_to_introduce


def display_the_entire_list(list_representation_of_complex_numbers, dictionary_representation_of_complex_numbers):
    print("The list representation of the list is:")
    print_the_list_of_complex_numbers_list_representation(list_representation_of_complex_numbers)
    print()

    print("The dictionary representation of teh list is:")
    print_the_list_of_complex_numbers_dictionary_representation(dictionary_representation_of_complex_numbers)
    print()


def SetA(list_representation_of_complex_numbers):  # prints the length and elements of a longest subarray of distinct numbers.
    result = []
    result = find_the_longest_subarray_of_distinct_complex_numbers(list_representation_of_complex_numbers)

    print("The length of the longest subarray with distinct numbers is =", result[0])
    print("The elements of the subarray are:")
    for i in range(result[1], result[2]):
        print(transform_into_string_the_list_representation_of_the_complex_number(
            list_representation_of_complex_numbers[i]))


def SetB(list_representation_of_complex_numbers):  # prints the length and elements of a longest increasing subsequence,
    # when considering each number's modulus

    print("The increasing subsequence while considering the modulus of the complex numbers is:")
    print_the_list_of_complex_numbers_list_representation(find_longest_increasing_subsequence(list_representation_of_complex_numbers))



def display_on_the_console_the_sequences_subarray_or_numbers_required_by_the_properties_assigned(
        list_representation_of_complex_numbers,
        how_many_complex_numbers_do_we_have):
    problem_from_which_set_to_solve = input("Introduce option A for solving problem 1 of Set A or "
                                            "Introduce option B for solving problem 9 of Set B: ")

    length_of_the_list_of_complex_number = how_many_complex_numbers_do_we_have

    if (problem_from_which_set_to_solve != "a" and problem_from_which_set_to_solve != "A" and
            problem_from_which_set_to_solve != "b" and problem_from_which_set_to_solve != "B"):

        while (problem_from_which_set_to_solve != "a" and problem_from_which_set_to_solve != "A" and
               problem_from_which_set_to_solve != "b" and problem_from_which_set_to_solve != "B"):
            problem_from_which_set_to_solve = input(
                "The set introduced is invalid. Please introduce a different option:")

    if (problem_from_which_set_to_solve == "a" or problem_from_which_set_to_solve == "A"):
        SetA(list_representation_of_complex_numbers)

    elif (problem_from_which_set_to_solve == "b" or problem_from_which_set_to_solve == "B"):
        SetB(list_representation_of_complex_numbers)


def Menu():
    list_representation_of_complex_numbers = generate_complex_number_list_representation()

    dictionary_representation_of_complex_numbers = generate_complex_number_dictionary_representation(
        list_representation_of_complex_numbers)

    while True:
        print(" Available options are:\n",
              "     1.Read a list of complex numbers (in z = a + bi form) from the console\n",
              "     2.Display the entire list of numbers on the console.\n",
              "     3.Display on the console the sequence, subarray or numbers required by the properties that were assigned to you.\n",
              "         Set A: 1.Length and elements of a longest subarray of distinct numbers.\n",
              "         Set B: 9.The length and elements of a longest increasing subsequence, when considering each number's modulus\n",
              "      4.Exit the application.")

        print()
        option_chosen = int(input("Introduce the option:"))

        if (option_chosen < 1 or option_chosen > 4):
            while (option_chosen < 1 or option_chosen > 4):
                option_chosen = int(input("The option introduced is not valid. Please introduce a different option:"))

        if (option_chosen == 1):
            read_a_list_of_complex_numbers(
                list_representation_of_complex_numbers, dictionary_representation_of_complex_numbers)
        elif (option_chosen == 2):
            display_the_entire_list(list_representation_of_complex_numbers, dictionary_representation_of_complex_numbers)
        elif (option_chosen == 3):
            display_on_the_console_the_sequences_subarray_or_numbers_required_by_the_properties_assigned(
                list_representation_of_complex_numbers, dictionary_representation_of_complex_numbers)
        elif (option_chosen == 4):
            break


Menu()
