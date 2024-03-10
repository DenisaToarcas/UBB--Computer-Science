#
# This is the program's UI module. The user interface and all interaction with the user (print and input statements) are found here
#

import functions


def Print_list_of_complex_numbers(list_of_complex_numbers):
    for i in range(0, len(list_of_complex_numbers)):
        print(i, ")", functions.transform_into_string_the_list_representation_of_the_complex_number(
            list_of_complex_numbers[i]))


def Add_a_number_to_list(list_of_complex_numbers, undoList):
    print(" 1. add <number>\n"
          " 2. insert <number> at <position>")

    which_one_to_be_done = input("Introduce the option:")

    if (which_one_to_be_done != "add number" and which_one_to_be_done != "insert number"):
        while (which_one_to_be_done != "add number" and which_one_to_be_done != "insert number"):
            which_one_to_be_done = input("The option introduced is actually invalid. "
                                         "Please introduce a different option:")

    if (which_one_to_be_done == "add number"):
        undoList.append([i for i in list_of_complex_numbers])
        complex_number_str_form = input(
            "Introduce the complex number here. Its form must be a+bi, where a,b are integers:")
        functions.Add_a_number(complex_number_str_form, list_of_complex_numbers)

    else:
        undoList.append([i for i in list_of_complex_numbers])
        print("The length of our list is= ", len(list_of_complex_numbers))

        complex_number_str_form = input(
            "Introduce the complex number here. Its form must be a+bi, where a,b are integers:")
        position_where_to_insert_the_complex_number = input(
            "Introduce the position where to insert the complex number:")

        if (len(position_where_to_insert_the_complex_number) > 2):
            while (len(position_where_to_insert_the_complex_number) > 2):
                position_where_to_insert_the_complex_number = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        position_where_to_insert_the_complex_number_int_form = functions.transform_str_in_int(
            position_where_to_insert_the_complex_number)

        if (
                position_where_to_insert_the_complex_number_int_form < 0 and position_where_to_insert_the_complex_number_int_form > len(
            list_of_complex_numbers)):
            while (
                    position_where_to_insert_the_complex_number_int_form < 0 and position_where_to_insert_the_complex_number_int_form > len(
                list_of_complex_numbers)):
                position_where_to_insert_the_complex_number = input(
                    "Position introduced is far out of our list.Please introduce a different position:")
                position_where_to_insert_the_complex_number_int_form = functions.transform_str_in_int(
                    position_where_to_insert_the_complex_number)

        functions.Insert_number_at_position(complex_number_str_form,
                                            position_where_to_insert_the_complex_number_int_form,
                                            list_of_complex_numbers)
    return undoList


def Modify_the_list_of_complex_numbers(list_of_complex_numbers, undoList):
    print(" 1. remove <position>\n"
          " 2. remove <start position> to <end position>\n"
          " 3. replace <old number> with <new number>")

    which_one_to_be_done = input("Introduce the option:")

    if (which_one_to_be_done != "remove position" and which_one_to_be_done != "remove start to end" and which_one_to_be_done != "replace"):
        while (which_one_to_be_done != "1" and which_one_to_be_done != "2" and which_one_to_be_done != "3"):
            which_one_to_be_done = input("The option introduced is actually invalid. "
                                         "Please introduce a different option:")
    if (which_one_to_be_done == "remove position"):
        undoList.append([functions.create_the_complex_number_list_representation(
            functions.get_the_real_part_of_the_complex_number_list_representation(i),
            functions.get_the_imaginary_part_of_the_complex_number_list_representation(i)) for i in
                         list_of_complex_numbers])
        print("The length of our list is= ", len(list_of_complex_numbers))

        position_from_where_to_remove_the_numbers = input(
            "Introduce the position from where to remove the complex number:")

        if (len(position_from_where_to_remove_the_numbers) > 2):
            while (len(position_from_where_to_remove_the_numbers) > 2):
                position_from_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        position_from_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
            position_from_where_to_remove_the_numbers)

        if (
                position_from_where_to_remove_the_numbers_int_form < 0 and position_from_where_to_remove_the_numbers_int_form > len(
            list_of_complex_numbers)):
            while (
                    position_from_where_to_remove_the_numbers_int_form < 0 and position_from_where_to_remove_the_numbers_int_form > len(
                list_of_complex_numbers)):
                position_from_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list.Please introduce a different position:")
                position_from_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
                    position_from_where_to_remove_the_numbers)
        functions.Remove_number_from_a_given_position(position_from_where_to_remove_the_numbers_int_form,
                                                      list_of_complex_numbers)

    elif (which_one_to_be_done == "remove start to end"):
        undoList.append([i for i in list_of_complex_numbers])
        print("The length of our list is= ", len(list_of_complex_numbers))

        position_from_where_to_remove_the_numbers = input(
            "Introduce the position from where to remove the complex numbers:")

        if (len(position_from_where_to_remove_the_numbers) > 2):
            while (len(position_from_where_to_remove_the_numbers) > 2):
                position_from_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        position_from_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
            position_from_where_to_remove_the_numbers)

        if (
                position_from_where_to_remove_the_numbers_int_form < 0 and position_from_where_to_remove_the_numbers_int_form > len(
            list_of_complex_numbers)):
            while (
                    position_from_where_to_remove_the_numbers_int_form < 0 and position_from_where_to_remove_the_numbers_int_form > len(
                list_of_complex_numbers)):
                position_from_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list.Please introduce a different position:")
                position_from_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
                    position_from_where_to_remove_the_numbers)

        position_until_where_to_remove_the_numbers = input(
            "Introduce the position until where to remove the complex numbers:")

        if (len(position_until_where_to_remove_the_numbers) > 2):
            while (len(position_until_where_to_remove_the_numbers) > 2):
                position_until_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        position_until_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
            position_until_where_to_remove_the_numbers)

        if (
                position_until_where_to_remove_the_numbers_int_form < 0 and position_until_where_to_remove_the_numbers_int_form > len(
            list_of_complex_numbers)):
            while (
                    position_until_where_to_remove_the_numbers_int_form < 0 and position_until_where_to_remove_the_numbers_int_form > len(
                list_of_complex_numbers)):
                position_until_where_to_remove_the_numbers = input(
                    "Position introduced is far out of our list.Please introduce a different position:")
                position_until_where_to_remove_the_numbers_int_form = functions.transform_str_in_int(
                    position_until_where_to_remove_the_numbers)

        functions.Remove_numbers_from_list(position_from_where_to_remove_the_numbers_int_form,
                                           position_until_where_to_remove_the_numbers_int_form, list_of_complex_numbers)

    else:
        undoList.append([i for i in list_of_complex_numbers])
        found = False
        Print_list_of_complex_numbers(list_of_complex_numbers)
        complex_number_str_form = input(
            "Introduce the complex number which you want to replace here. Its form must be a+bi, where a,b are integers:")
        complex_number_to_be_replaced = functions.transform_the_complex_number_from_str_to_int(complex_number_str_form)

        complex_number_str_form = input(
            "Introduce the complex number with which you would like to replace the previous one:")
        replacer = functions.transform_the_complex_number_from_str_to_int(complex_number_str_form)

        for i in range(0, len(list_of_complex_numbers)):
            if (functions.get_the_real_part_of_the_complex_number_list_representation(list_of_complex_numbers[i]) ==
                    functions.get_the_real_part_of_the_complex_number_list_representation(
                        complex_number_to_be_replaced) and
                    functions.get_the_imaginary_part_of_the_complex_number_list_representation(
                        list_of_complex_numbers[i]) ==
                    functions.get_the_imaginary_part_of_the_complex_number_list_representation(
                        complex_number_to_be_replaced)):
                found = True
                list_of_complex_numbers[i] = replacer

        if (found == False):
            print("The complex number to be replaced is not part of the list. Sorry mate :)))")

    return undoList


def Display_the_list_of_complex_numbers(list_of_complex_numbers):
    print(" 1. list\n"
          " 2. list real <start position> to <end position>\n"
          " 3. list modulo [ < | = | > ] <number>")

    which_one_to_be_done = input("Introduce the option:")

    if (which_one_to_be_done != "list" and which_one_to_be_done != "list real" and which_one_to_be_done != "list modulo"):
        while (which_one_to_be_done != "list" and which_one_to_be_done != "list real" and which_one_to_be_done != "list modulo"):
            which_one_to_be_done = input("The option introduced is actually invalid. "
                                         "Please introduce a different option:")
    if (which_one_to_be_done == "list"):
        print("The list of complex numbers is:\n")
        Print_list_of_complex_numbers(list_of_complex_numbers)

    elif (which_one_to_be_done == "list real"):
        start_position_for_printing_string_form = input(
            "Introduce the starting position from where you want to print the real numbers:")

        if (len(start_position_for_printing_string_form) > 2):
            while (len(start_position_for_printing_string_form) > 2):
                start_position_for_printing_string_form = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        start_position_for_printing = functions.transform_str_in_int(start_position_for_printing_string_form)

        if (start_position_for_printing < 0 and start_position_for_printing > len(list_of_complex_numbers) - 1):
            while (start_position_for_printing < 0 and start_position_for_printing > len(list_of_complex_numbers) - 1):
                start_position_for_printing_string_form = input(
                    "Could not perform the listing. The position introduced is out of the list."
                    "Please introduce a different value:")

        end_position_for_printing_string_form = input(
            "Introduce the ending position until where you want to print the real numbers:")

        if (len(end_position_for_printing_string_form) > 2):
            while (len(end_position_for_printing_string_form) > 2):
                end_position_for_printing_string_form = input(
                    "Position introduced is far out of our list or is invalid. Please introduce a different position:")

        end_position_for_printing = functions.transform_str_in_int(end_position_for_printing_string_form)

        if (end_position_for_printing < 0 and end_position_for_printing > len(list_of_complex_numbers)):
            while (end_position_for_printing < 0 and end_position_for_printing > len(list_of_complex_numbers)):
                end_position_for_printing_string_form = input(
                    "Could not perform the listing. The position introduced is out of the list."
                    "Please introduce a different value:")

        if (end_position_for_printing < start_position_for_printing):
            print("The starting position is smaller than the ending position, so the program will switch them.")
            auxiliary = start_position_for_printing
            start_position_for_printing = end_position_for_printing
            end_position_for_printing = auxiliary

        real_numbers = functions.Get_real_numbers_between_two_given_positions(start_position_for_printing, end_position_for_printing,
                                                                              list_of_complex_numbers)

        if (len(real_numbers) == 0):
            print("There are no real numbers in our list.")
        else:
            print("The list of real numbers is:")
            for i in range(0, len(real_numbers)):
                print(real_numbers[i])

    else:
        complex_numbers_compared = []
        sign = input("Introduce the sign for comparing the modulos of the numbers. This can be < or = or >:")
        if (sign != "<" and sign != "=" and sign != ">"):
            while (sign != "<" and sign != "=" and sign != ">"):
                sign = input(
                    "The sign introduced is not a comparison type of operand. Please introduce a different sign:")

        modulo_with_which_we_compare = input(
            "Introduce the modulo with which you would like to compare the complex numbers' modulos:")
        if (modulo_with_which_we_compare[0] < "1" and modulo_with_which_we_compare[0] > "9"):
            while (modulo_with_which_we_compare[0] < "1" and modulo_with_which_we_compare[0] > "9"):
                modulo_with_which_we_compare = input(
                    "The value introduced is not a real number. Please introduce a different value for the modulo:")

        modulo_with_which_we_compare_int_form = functions.transform_str_in_int(modulo_with_which_we_compare)

        complex_numbers_compared = functions.Compare_the_modulus_of_the_complex_numbers(
            list_of_complex_numbers, sign, modulo_with_which_we_compare_int_form)

        if (len(complex_numbers_compared) == 0):
            print("There are no complex numbers with their modulo satisfying the requirement.")
        else:
            print("The list of complex numbers satisfying the requirement is:")
            Print_list_of_complex_numbers(complex_numbers_compared)


def Filter_the_list_of_complex_numbers(list_of_complex_numbers, undoList):
    print(" 1. filter real\n"
          " 2. filter modulo [ < | = | > ] <number>\n")

    which_one_to_be_done = input("Introduce the option:")

    if (which_one_to_be_done != "filter real" and which_one_to_be_done != "filter modulo"):
        while (which_one_to_be_done != "filter real" and which_one_to_be_done != "filter modulo"):
            which_one_to_be_done = input("The option introduced is actually invalid. "
                                         "Please introduce a different option:")

    if (which_one_to_be_done == "filter real"):
        undoList.append([i for i in list_of_complex_numbers])
        list_of_complex_numbers = functions.Get_real_numbers(list_of_complex_numbers)

    if (which_one_to_be_done == "filter modulo"):
        undoList.append([i for i in list_of_complex_numbers])
        complex_numbers_satisfying_the_modulo_requirement = []
        sign_of_comparison = input(
            "Introduce the comparison sign for comparing the modulos of the numbers. This can be < or = or >:")
        if (sign_of_comparison != "<" and sign_of_comparison != "=" and sign_of_comparison != ">"):
            while (sign_of_comparison != "<" and sign_of_comparison != "=" and sign_of_comparison != ">"):
                sign_of_comparison = input(
                    "The sign_of_comparison introduced is not a comparison type of operand. Please introduce a different sign_of_comparison:")

        modulo_with_which_we_compare = input(
            "Introduce the modulo with which you would like to compare the complex numbers' modulos:")
        if (modulo_with_which_we_compare[0] < "1" and modulo_with_which_we_compare[0] > "9"):
            while (modulo_with_which_we_compare[0] < "1" and modulo_with_which_we_compare[0] > "9"):
                modulo_with_which_we_compare = input(
                    "The value introduced is not a real number. Please introduce a different value for the modulo:")

            modulo_with_which_we_compare_int_form = functions.transform_str_in_int(modulo_with_which_we_compare)

            complex_numbers_satisfying_the_modulo_requirement = functions.Compare_the_modulus_of_the_complex_numbers(
            list_of_complex_numbers, sign_of_comparison, modulo_with_which_we_compare_int_form)

        if (len(complex_numbers_satisfying_the_modulo_requirement) == 0):
            list_of_complex_numbers = []
            print("There are no complex numbers with their modulo satisfying the requirement.")
        else:
            list_of_complex_numbers = complex_numbers_satisfying_the_modulo_requirement

    return list_of_complex_numbers


def Menu():
    undoList = []
    list_of_complex_numbers = []
    list_of_complex_numbers = functions.generate_complex_number_list_representation()
    while True:
        print(" Available options are:\n",
              "     (A) Add a number\n",
              "     (B) Modify numbers\n",
              "     (C) Display numbers having different properties\n",
              "     (D) Filter the list\n"
              "      (E) Undo")

        print()
        option_chosen = input("Introduce the option:")
        if (option_chosen == "add"):
            Add_a_number_to_list(list_of_complex_numbers, undoList)

        elif (option_chosen == "modify"):
            Modify_the_list_of_complex_numbers(list_of_complex_numbers, undoList)

        elif (option_chosen == "display"):
            Display_the_list_of_complex_numbers(list_of_complex_numbers)

        elif (option_chosen == "filter"):
            list_of_complex_numbers = Filter_the_list_of_complex_numbers(list_of_complex_numbers, undoList)

        elif (option_chosen == "undo"):
            if len(undoList) > 0:
                list_of_complex_numbers = undoList.pop()
                print("The Undo operation was performed correctly!")
            else:
                print("We cannot perform the Undo operation!")

        else:
            while(option_chosen != "add" and option_chosen != "modify" and option_chosen != "display" and option_chosen != "filter" and option_chosen != "undo"):
                option_chosen = input("The option introduced is actually invalid. Please introduce a different option:")
