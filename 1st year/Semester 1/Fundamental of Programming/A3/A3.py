import random
import timeit


#FUNCTIONS THAT SORT LISTS

"""
        The array is virtually split into a sorted and an unsorted part. 
        Values from the unsorted part are picked and placed at the correct position in the sorted part.      
"""
def insert_sort(array : list):
    for i in range(1, len(array)):
        auxiliary = array[i]
        position = i - 1
        while (position >= 0 and array[position] > auxiliary):
            array[position + 1] = array [position]
            position = position - 1
            array[position + 1] = auxiliary
    return



"""
    Stooge Sort is a recursive sorting algorithm.
    It generally divides the array into two overlapping parts (2/3 each). 
    After that it performs sorting in first 2/3 part and then it performs sorting in last 2/3 part. 
    And then, sorting is done on first 2/3 part to ensure that the array is sorted.
"""
def stooge_sort(array : list):
    left = 0                        #left is the lower bound of the subarray which needs to be sorted
    right = len(array) - 1          #right is the upper bound of the subarray that needs to be sorted

    sort_with_stooge(array, left, right)


def sort_with_stooge(array : list, left : int, right : int):
    if (left >= right):          #if our lower bound goes over the upper one, it means that the subarray is sorted
        return
    """
    If the first element is greater than the last one, we swap them
    """

    if (array[left] > array[right]):
        auxiliary = array[left]
        array[left] = array[right]
        array[right] = auxiliary

        """
        If there are more than 2 elements in the subarray that need to be sorted, we split the subarray again, using the same algorithm
        """
    if (right - left + 1 > 2):
          third_part_of_array = (int)((right - left + 1) / 3)
          sort_with_stooge(array, left, right - third_part_of_array)        #we sort the first 2/3 part of the array
          sort_with_stooge(array, left + third_part_of_array, right)        #we sort the last 2/3 part of the array
          sort_with_stooge(array, left, right - third_part_of_array)        #we resort the first 2/3 part of the array to ensure that the whole array is sorted

############################################################################################

#FUNCTIONS THAT GENERATE LISTS

def GenerateListOfNRandomNumbers(arraylenght):
    ListOfRandomNo = []
    for i in range(arraylenght):
        ListOfRandomNo.append(random.randint(0,100))
    return ListOfRandomNo
    #this function generates a list of random numbers

def generateRandombutSortedList(arraylenght):
    ListOfRandomNo = []
    LastGeneratedElement = int(5)
    for i in range(0, arraylenght):
        ListOfRandomNo.append(LastGeneratedElement)
        LastGeneratedElement = LastGeneratedElement + random.randint(1,10)
    return ListOfRandomNo
    #this function generates a list of random numbers, that is sorted increasingly

def generateDecreasingRandomSortedList(arraylenght):
    ListOfRandomNo = []
    LastGeneratedElement = int(100)
    for i in range(0, arraylenght):
        ListOfRandomNo.append(LastGeneratedElement)
        LastGeneratedElement = LastGeneratedElement + random.randint(-5, -2)
    return ListOfRandomNo
    #this function generates a list of random numbers, that is sorted decreasingly


##########################################################################################

#FUNCTIONS THAT PRINT THE COMPLEXITY AND RUNTIME OF  THE ALGORITHMS

def best_case(array, arraylenght, chosen_option):
    if (chosen_option == 1):
        array = generateRandombutSortedList(arraylenght)
        print()
        print("Best case for insertion sort is when the list is already sorted.")

        print("The lenght of the array is:", arraylenght)
        print("For this array, the complexity of the insertion sort algorithm is = O(",arraylenght,")")
        initial_time = timeit.default_timer()
        insert_sort(array)
        final_time =timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for insertion sort in best case for this array is: ", execution_time)
        #Explanation: when the list is sorted,
        #the problem resumes to comparing every element from the list with its predecesors which are in the right order already.
        #So, we get O(n) from FOR I IN RANGE (1, len(array)) as it makes n iterations.
        #O(n^2)0

    if (chosen_option == 2):
        array = GenerateListOfNRandomNumbers(arraylenght)
        print()
        print("Best case for stooge sort is when the array is unsorted.")

        print("The length of the array is:", arraylenght)
        print("For this array, the complexity of the stooge sort algorithm is = O(", arraylenght ** 2.709,")")
        initial_time = timeit.default_timer()
        stooge_sort(array)
        final_time = timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for stooge sort in best case for this array is: ", execution_time)
        #2.709 = log in base 3/2 of 3
        #Explanation: Either the list is sorted or not, the recursive calls will be invocated in the same number for both cases.
        #That's why a randomly generated list will actually be the best case, as we at least proceed to do some swaps between the list's elements.


def worst_case(array, arraylenght, chosen_option):
    if (chosen_option == 1):
        array = generateDecreasingRandomSortedList(arraylenght)
        print()
        print("Worst case for insertion sort is when the array is already sorted, but reversed.")

        print("The lenght of the array is:", arraylenght)
        print("For this array, the complexity of the insertion sort algorithm is = O(",arraylenght * arraylenght,")")
        initial_time = timeit.default_timer()
        insert_sort(array)
        final_time = timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for insertion sort in worst case for this array is: ", execution_time)
        #Explanation: when the list is sorted, but reversed,
        #the problem resumes to comparing every element from the list with its predecesors and move it to the beggining of the array.
        #So, we get O(n) from FOR I IN RANGE (1, len(array)) as it makes n iterations and another O(n) from WHILE....

    if (chosen_option == 2):
        array = generateRandombutSortedList(arraylenght)
        print()
        print("Worst case for stooge sort is when the array is already sorted.")

        print("The lenght of the array is:", arraylenght)
        print("For this array, the complexity of the stooge sort algorithm is = O(", arraylenght ** 2.709,")")
        initial_time = timeit.default_timer()
        stooge_sort(array)
        final_time = timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for stooge sort in worst case for this array is: ", execution_time)
        #Worst case for stooge sort is when the list is already being sorted,
        #because it will make as many calls for all the subsequences as it does when being randomly generated.
        #we waste the time trying to sort the array again, no swaps take place only the recursive calls happen.

def average_case(array, arraylenght, chosen_option):

    if (chosen_option == 1):
        array = GenerateListOfNRandomNumbers(arraylenght)
        print()
        print("Average case for insertion sort is when the array is randomly generated. The array is not sorted neither increasingly, not decreasingly.")

        print("The length of the array is:", arraylenght)
        print("For this array, the complexity of the insertion sort algorithm is =O(", arraylenght * arraylenght, ")")
        initial_time = timeit.default_timer()
        insert_sort(array)
        final_time = timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for insertion sort in average case for this array is: ", execution_time)

    if (chosen_option == 2):
        array = GenerateListOfNRandomNumbers(arraylenght)
        print()
        print("Average case for stooge sort is when the array is randomly generated.")

        print("The length of the array is:", arraylenght)
        print("For this array, the complexity of the stooge sort algorithm is = O(", arraylenght ** 2.709,")")
        initial_time = timeit.default_timer()
        stooge_sort(array)
        final_time = timeit.default_timer()
        execution_time = final_time - initial_time
        print("The runtime for stooge sort in average case for this array is: ", execution_time)


##########################################################################################

#MENU FUNCTION

def menu():
    while True:
        print()
        print("Generate a list of `n` random natural numbers. Generated numbers must be between `0` and `100`.")
        array = []
        print("The lengh of the initial array will be equal to:")
        arraylenght = int(input())

        print("1. Sort the list using the insert sort algorithm.")
        print("2. Sort the list using the stooge sort algorithm.")
        print("3. Exit the program")

        chosen_option = 0
        chosen_option = int(input("Choose an option between 1 and 3:"))

        if (chosen_option < 1 or chosen_option > 3):
            while (chosen_option < 1 or chosen_option > 3):
                print("The option introduced is invalid. Please introduce a different option. It must be between 1 and 3.")
                chosen_option = int(input())

        if (chosen_option == 1):            #INSERT SORT

                print("a. Best case")
                print("b. Average case")
                print("c. Worst case")

                case_option = str(input("Choose the case according to which the program will display the complexity and runtime:"))

                if (case_option < 'a' or case_option > 'c'):
                    while(case_option < 'a' or case_option > 'c'):
                        print("The option introduced is invalid. Please introduce a different option.")
                        case_option = str(input())

                if (case_option == 'a'):            #best case scenario
                    for i in range(0, 5):
                        best_case(array, arraylenght, chosen_option)
                        arraylenght = 2 * arraylenght


                else:
                    if (case_option == 'b'):        #average case scenario
                        for i in range(0, 5):
                            average_case(array, arraylenght, chosen_option)
                            arraylenght = 2 * arraylenght

                    else:
                        if (case_option == 'c'):     #worst case scenario
                            for i in range(0, 5):
                                worst_case(array, arraylenght, chosen_option)
                                arraylenght = 2 * arraylenght




        else:
            if (chosen_option == 2):            #STOOGE SORT

                    print("a. Best case")
                    print("b. Average case")
                    print("c. Worst case")

                    case_option = str(input("Choose the case according to which the program will display the complexity and runtime:"))

                    if (case_option < 'a' or case_option > 'c'):
                        while (case_option < 'a' or case_option > 'c'):
                            print("The option introduced is invalid. Please introduce a different option.")
                            case_option = str(input())

                    if (case_option == 'a'):                    #best case scenario
                        for i in range(0, 5):
                            best_case(array, arraylenght, chosen_option)
                            arraylenght = 2 * arraylenght

                    else:
                        if (case_option == 'b'):                #average case scenario
                            for i in range(0, 5):
                                average_case(array, arraylenght, chosen_option)
                                arraylenght = 2 * arraylenght

                        else:
                            if (case_option == 'c'):            #worst case scenario
                                for i in range(0, 5):
                                    worst_case(array, arraylenght, chosen_option)
                                    arraylenght = 2 * arraylenght

def main_program():
    menu()

####################################################################################

main_program()