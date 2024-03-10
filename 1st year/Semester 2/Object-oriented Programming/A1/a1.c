/*
 * 7.
 * 1. Read sequences of positive integer numbers (reading of each sequence ends by 0,
 * reading of all the sequences ends by -1) and determine the maximum element of each
 * sequence and the maxim element of the global sequence.
 * 2. Given a vector of numbers, find the longest contiguous subsequence such that all
 * elements are in a given interval.


 */
#include <stdio.h>
#include <string.h>

int read_sequences(int vector[])
{
    int element = 0, number_of_elements= 0, k;
    printf("\nEnter the elements of the vector:\n");
    while (scanf_s("%d", &element)){
        vector[number_of_elements] = element;
        number_of_elements += 1;
        if (element == -1)
            break;
    }
    return number_of_elements;
}

int find_maximum_of_all_sequences(int vector[], int vector_of_max[]) {
    int count = 0;
    int length = read_sequences(vector);
    int maximum = 0;
    for (int i = 0; i < length; i++) {
        if (vector[i] == 0) {
            vector_of_max[count] = maximum;
            count += 1;
            maximum = 0;
        } else {
            if (vector[i] > maximum)
                maximum = vector[i];
        }
    }
    if (maximum != 0) {
        vector_of_max[count] = maximum;
        count += 1;
    }

    return count;
}

int find_maximum_global(int number_of_elements_for_max, const int vector_of_max[])
{
    int maximum_global=0;
    for (int i=0; i< number_of_elements_for_max; i++){
        if (vector_of_max[i] > maximum_global)
            maximum_global = vector_of_max[i];
    }
    return maximum_global;
}

int find_longest_contiguous_seq(int no_of_elems, const int vector[], int longest_seq[], int lower_bound, int upper_bound) {
    int maximum_length = 0;
    int intermediate_length = 1;
    int starting_position = 0;
    int ending_position = 0;
    int start_seq = 0;
    for (int i = 0; i < no_of_elems; i++) {
        if (vector[i] >= lower_bound && vector[i] <= upper_bound)
            intermediate_length += 1;
        else {
            if (intermediate_length > maximum_length) {
                starting_position = start_seq;
                ending_position = i;
                maximum_length = intermediate_length;
                start_seq = i;
                intermediate_length = 1;
            }
        }
    }
    if (intermediate_length > maximum_length) {
        starting_position = start_seq;
        ending_position = no_of_elems;
        maximum_length = intermediate_length;
    }
    for (int i = starting_position; i < ending_position; i++)
        longest_seq[i] = vector[i];

    return ending_position - starting_position;
}


 void menu()
 {
     printf("MENU: \n");
     printf("1. Read sequences of positive numbers, find the maximums of all "
            "the sequences and the global maximum.\n");
     printf("2. Find the longest contiguous subsequence of elements that are in "
            "the given interval for a given vector.\n");
     printf("0. Exit\n");
 }

int main() {
    char option_chosen[2];

    while (1) {
        menu();
        printf("Choose between solving problem 1 or 2:");
        scanf_s("%s", &option_chosen);
        if (strstr("120", option_chosen) == NULL || strlen(option_chosen) > 1) {
            while (strstr("ab0", option_chosen) == NULL) {
                printf("Invalid option given!");
                menu();
            }
        }
        if (strcmp(option_chosen, "0") == 0) {
            break;
        }
        switch (option_chosen[0] - 48) {

            case 1: {
                int vector[100];
                int vector_of_max[100];
                int number_of_elements_for_max;
                int maximum_global = 0;
                number_of_elements_for_max = find_maximum_of_all_sequences(vector, vector_of_max);
                printf("The maximums for every sequence are:\n");
                for (int i = 0; i < number_of_elements_for_max; i++) {
                    printf("%d", vector_of_max[i]);
                    printf(" ");
                }

                maximum_global = find_maximum_global(number_of_elements_for_max, vector_of_max);
                printf("\nThe global maximum is:\n");
                printf("%d", maximum_global);
                printf("%s", "\n");
                break;
            }
            case 2: {
                int vector[100];
                int longest_seq[100];
                int lower_bound = 0;
                int upper_bound = 0;
                int number_of_elements = 0;
                int no_of_elems_from_seq = 0;
                printf("\nGive the lower and the upper bound for the interval:");
                printf("\n-lower bound:");
                scanf_s("%d", &lower_bound);
                printf("\n-upper bound:");
                scanf_s("%d", &upper_bound);
                number_of_elements = read_sequences(vector);
                no_of_elems_from_seq = find_longest_contiguous_seq(number_of_elements, vector, longest_seq, lower_bound,
                                                                   upper_bound);

                printf("\nLongest contiguous sequence of elems from this interval is:\n");
                for (int i = 0; i < no_of_elems_from_seq; i++) {
                    printf("%d", longest_seq[i]);
                    printf(" ");
                    break;
                }

            }
            default:
                break;
        }
    }
    return 0;
}