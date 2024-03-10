def compute_sum(given_list_of_numbers, if_the_number_is_part_of_the_partition_or_not):
    sum_of_the_partition = 0
    for i in range(len(given_list_of_numbers)):
        sum_of_the_partition += (if_the_number_is_part_of_the_partition_or_not[i] * given_list_of_numbers[i])
    return sum_of_the_partition


def generate_the_partitions(given_list_of_numbers, if_the_number_is_part_of_the_partition_or_not):
    first_partition, second_partition = [], []

    for i in range(len(given_list_of_numbers)):
        if if_the_number_is_part_of_the_partition_or_not[i] == 1:
            second_partition.append(given_list_of_numbers[i])
        else:
            first_partition.append(given_list_of_numbers[i])

    # print (first_partition)
    # print (second_partition)
    return first_partition, second_partition


def find_the_partitions(given_list_of_numbers, half_sum_of_the_given_list):
    if_the_number_is_part_of_the_partition_or_not = [-1 for _ in range(len(given_list_of_numbers))]

    i = 0
    while 0 <= i <= len(given_list_of_numbers):
        if i == len(given_list_of_numbers):
            if compute_sum(given_list_of_numbers, if_the_number_is_part_of_the_partition_or_not) == \
                    half_sum_of_the_given_list:
                return generate_the_partitions(given_list_of_numbers, if_the_number_is_part_of_the_partition_or_not)
            i -= 1
            continue

        if if_the_number_is_part_of_the_partition_or_not[i] == -1:
            if_the_number_is_part_of_the_partition_or_not[i] = 0
            i += 1
        elif if_the_number_is_part_of_the_partition_or_not[i] == 0:
            if_the_number_is_part_of_the_partition_or_not[i] = 1
            i += 1
        else:
            if_the_number_is_part_of_the_partition_or_not[i] = -1
            i -= 1

    return [], []

def Menu():
    while True:
        print()
        given_list_of_numbers = []
        print("The length of the given_list_of_numbers of which we will find the partitions will be equal to:")
        length_of_the_given_list = int(input())

        if (length_of_the_given_list <= 0):
            while (length_of_the_given_list <= 0):
                print("The given_list_of_numbers cannot be generated, due to the length being a negative number."
                      "Please introduce a different value:")
                length_of_the_given_list = int(input())

        print("Introduce the list of numbers:")
        for i in range(0, length_of_the_given_list):
            value = int(input())
            given_list_of_numbers.append(value)

        print()

        first_partition = []
        second_partition = []
        sum_of_the_given_list = 0

        for i in range(len(given_list_of_numbers)):
            sum_of_the_given_list = sum_of_the_given_list + given_list_of_numbers[i]
            # print(s)
        if sum_of_the_given_list % 2 == 1:
            print("It can not be partitioned in two subsets")
        else:
            first_partition, second_partition = find_the_partitions(given_list_of_numbers, sum_of_the_given_list // 2)

        print(first_partition)
        print(second_partition)


def main_program():
    Menu()

main_program()

