#
# The program's functions are implemented here. There is no user interaction in this file, therefore no input/print statements. Functions here
# communicate via function parameters, the return statement and raising of exceptions. 
#
import random
import math


def create_the_complex_number_list_representation(real_part: int, imaginary_part: int):
    """
    Creates a new complex number

    :return: The new complex number
    """
    return [real_part, imaginary_part]


def generate_complex_number_list_representation():
    list_of_complex_numbers = []

    for i in range(0, 10):
        real_part = random.randint(0, 100)
        imaginary_part = random.randint(0, 100)

        complex_number = create_the_complex_number_list_representation(real_part, imaginary_part)
        list_of_complex_numbers.append(complex_number)

    return list_of_complex_numbers


def transform_the_complex_number_from_str_to_int(complex_number_str_form):
    i = 0
    real_part = 0
    imaginary_part = 0
    while (complex_number_str_form[i] != "+"):
        real_part = real_part * 10 + int(complex_number_str_form[i])
        i = i + 1
    i = i + 1

    while (complex_number_str_form[i] != "i"):
        imaginary_part = imaginary_part * 10 + int(complex_number_str_form[i])
        i = i + 1

    return [real_part, imaginary_part]


def transform_str_in_int(number_in_string_form):
    i = 0
    number_in_int_form = 0
    while (i != len(number_in_string_form)):
        number_in_int_form = number_in_int_form * 10 + int(
            number_in_string_form[i])
        i = i + 1

    return number_in_int_form


def Add_a_number(complex_number_str_form, list_of_complex_numbers):
    complex_number = transform_the_complex_number_from_str_to_int(complex_number_str_form)
    list_of_complex_numbers.append(complex_number)


def Insert_number_at_position(complex_number_str_form, position_where_to_insert_the_complex_number,
                              list_of_complex_numbers):
    complex_number = transform_the_complex_number_from_str_to_int(complex_number_str_form)
    if (position_where_to_insert_the_complex_number == len(list_of_complex_numbers)):
        list_of_complex_numbers.append(complex_number)
    else:
        list_of_complex_numbers.append([0, 0])

        auxiliary_1 = list_of_complex_numbers[position_where_to_insert_the_complex_number]
        auxiliary = list_of_complex_numbers[position_where_to_insert_the_complex_number + 1]
        list_of_complex_numbers[position_where_to_insert_the_complex_number] = complex_number
        list_of_complex_numbers[position_where_to_insert_the_complex_number + 1] = auxiliary_1

        if (position_where_to_insert_the_complex_number + 2 < len(list_of_complex_numbers)):
            for i in range(position_where_to_insert_the_complex_number + 2, len(list_of_complex_numbers)):
                auxiliary_1 = list_of_complex_numbers[i]
                list_of_complex_numbers[i] = auxiliary
                auxiliary = auxiliary_1


def Remove_number_from_a_given_position(position_from_where_to_remove_the_number_int_form, list_of_complex_numbers):
    for i in range(position_from_where_to_remove_the_number_int_form, len(list_of_complex_numbers) - 1):
        list_of_complex_numbers[i] = list_of_complex_numbers[i + 1]

    list_of_complex_numbers.pop()


def Remove_numbers_from_list(position_from_where_to_remove_the_number_int_form,
                             position_until_where_to_remove_the_number_int_form, list_of_complex_numbers):
    i = position_from_where_to_remove_the_number_int_form
    while (position_until_where_to_remove_the_number_int_form >= position_from_where_to_remove_the_number_int_form):
        list_of_complex_numbers.remove(list_of_complex_numbers[i])
        position_until_where_to_remove_the_number_int_form = position_until_where_to_remove_the_number_int_form - 1


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


def Get_real_numbers_between_two_given_positions(start_position_for_printing, end_position_for_printing, list_of_complex_numbers):
    real_numbers = []
    for i in range(start_position_for_printing, end_position_for_printing):
        if (get_the_imaginary_part_of_the_complex_number_list_representation(list_of_complex_numbers[i]) == 0):
            real_numbers.append(get_the_real_part_of_the_complex_number_list_representation(list_of_complex_numbers[i]))

    if (end_position_for_printing == len(list_of_complex_numbers) - 1):
        if (get_the_imaginary_part_of_the_complex_number_list_representation(
                list_of_complex_numbers[end_position_for_printing]) == 0):
            real_numbers.append(list_of_complex_numbers[end_position_for_printing])

    return real_numbers


def get_modulus_of_complex_number(complex_number):
    real_part = get_the_real_part_of_the_complex_number_list_representation(complex_number)
    imaginary_part = get_the_imaginary_part_of_the_complex_number_list_representation(complex_number)

    return math.sqrt(real_part * real_part + imaginary_part * imaginary_part)


def if_modulus_of_complex_number_is_less(complex_number_in_list, modulo_with_which_we_compare):
    if (get_modulus_of_complex_number(complex_number_in_list) < modulo_with_which_we_compare):
        return True
    else:
        return False


def if_modulus_of_complex_number_is_greater(complex_number_in_list, modulo_with_which_we_compare):
    if (get_modulus_of_complex_number(complex_number_in_list) > modulo_with_which_we_compare):
        return True
    else:
        return False


def if_modulus_of_complex_number_is_equal(complex_number_in_list, modulo_with_which_we_compare):
    if (get_modulus_of_complex_number(complex_number_in_list) == modulo_with_which_we_compare):
        return True
    else:
        return False


def Compare_the_modulus_of_the_complex_numbers(list_of_complex_numbers, sign, modulo_with_which_we_compare):
    complex_numbers_compared = []

    if (sign == "<"):
        for i in range(0, len(list_of_complex_numbers)):
            if (if_modulus_of_complex_number_is_less(list_of_complex_numbers[i], modulo_with_which_we_compare) == True):
                complex_numbers_compared.append(list_of_complex_numbers[i])

    elif (sign == ">"):
        for i in range(0, len(list_of_complex_numbers)):
            if (if_modulus_of_complex_number_is_greater(list_of_complex_numbers[i], modulo_with_which_we_compare) == True):
                complex_numbers_compared.append(list_of_complex_numbers[i])

    else:
        for i in range(0, len(list_of_complex_numbers)):
            if (if_modulus_of_complex_number_is_equal(list_of_complex_numbers[i], modulo_with_which_we_compare) == True):
                complex_numbers_compared.append(list_of_complex_numbers[i])

    return complex_numbers_compared

def Get_real_numbers(list_of_complex_numbers):
    real_numbers = []

    for i in range(0, len(list_of_complex_numbers)):
        if (get_the_imaginary_part_of_the_complex_number_list_representation(list_of_complex_numbers[i]) == 0):
            real_numbers.append(list_of_complex_numbers[i])

    return real_numbers
