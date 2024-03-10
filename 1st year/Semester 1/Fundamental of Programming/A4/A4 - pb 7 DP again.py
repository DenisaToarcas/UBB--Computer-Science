"""
7.
Given a set of integers A, determine if it can be partitioned into two subsets with equal sum.
For example, set A = { 1, 1, 1, 1, 2, 3, 5 } can be partitioned into sets A1 = { 1, 1, 2, 3 }
and A2 = { 1, 1, 5 }, each of them having sum 7. Display one such possibility.

1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false.
2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2.

We just need to store all the values in a matrix.

"""

import random


def Generate_List_Of_Random_Numbers(arraylength):
    List_Of_Random_Numbers = []

    for i in range(0, arraylength):
        List_Of_Random_Numbers.append(random.randint(0, 100))

    return List_Of_Random_Numbers


def print_the_subset(subset_of_array):
    print("The two partitions of the array with equal sums are:")
    print(subset_of_array)

    # TODO print the other partition


def create_subsequence_that_has_the_sum_equal_to_half_the_array_sum(array, position_in_array, subset_of_array,
                                                                    half_of_sum_of_array, sum_of_partitions, index):
    if (sum_of_partitions[position_in_array + 1][len(subset_of_array)] == half_of_sum_of_array):
        return True
    if (index == len(array) and sum_of_partitions[position_in_array + 1][len(subset_of_array)] != half_of_sum_of_array):
        return False

    subset_of_array.append(array[position_in_array + index])
    sum_of_partitions[position_in_array + 1][len(subset_of_array)] = sum_of_partitions[position_in_array + 1][
                                                                         len(subset_of_array) - 1] + array[
                                                                         position_in_array + index]

    create_subsequence_that_has_the_sum_equal_to_half_the_array_sum(array, position_in_array, subset_of_array,
                                                                    half_of_sum_of_array, sum_of_partitions, index + 1)


def find_the_partitions_of_the_whole_array(array, sum_of_array):
    whether_the_subset_is_found_or_not = False
    subset_of_array = []
    position_in_array = 0

    sum_of_partitions = [[0 for _ in range(0, len(array) + 1)] for _ in range(0, len(array) + 1)]

    for i in range(0, len(array) + 1):
        for j in range(0, len(array) + 1):
            sum_of_partitions[i][j] = 0

    while (whether_the_subset_is_found_or_not == False and position_in_array != len(array)):
        index = position_in_array
        whether_the_subset_is_found_or_not = create_subsequence_that_has_the_sum_equal_to_half_the_array_sum(array,
                                                                                                             position_in_array,
                                                                                                             subset_of_array,
                                                                                                             sum_of_array // 2,
                                                                                                             sum_of_partitions,
                                                                                                             index)
        print(subset_of_array)
        print()
        print(sum_of_partitions)
        subset_of_array.clear()
        position_in_array = position_in_array + 1

    if (whether_the_subset_is_found_or_not == True):
        print_the_subset(subset_of_array)
    else:
        print("There does not exist any partitions of the array with equal sums.")


def Menu():
    while True:
        print()
        print("Generate a list of random natural numbers.")
        array = []
        print("The length of the array of which we will find the partitions will be equal to:")
        arraylength = int(input())

        if (arraylength <= 0):
            while (arraylength <= 0):
                print("The array cannot be generated, due to the length being a negative number."
                      "Please introduce a different value:")
                arraylength = int(input())

        array = Generate_List_Of_Random_Numbers(arraylength)
        print(array)
        print()

        sum_of_array = 0

        for i in range(0, len(array)):
            sum_of_array = sum_of_array + array[i]

        if (sum_of_array % 2 == 1):
            print("There does not exist any partitions of the array with equal sums.")
        else:
            find_the_partitions_of_the_whole_array(array, sum_of_array)


def main_program():
    Menu()

find_the_partitions_of_the_whole_array([1, 2, 3, 4], 10)

#main_program()
