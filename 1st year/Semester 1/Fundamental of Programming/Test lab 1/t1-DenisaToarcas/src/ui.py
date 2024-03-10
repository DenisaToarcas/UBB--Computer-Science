from functions import GeneratePhones
from functions import add_phone_to_list_of_phones
from functions import find_phone_with_given_manufacturer
from functions import return_str_of_the_phone
from functions import increase_price_of_given_phone

def print_list_of_phones(list_of_phones):
    for i in range(0, len(list_of_phones)):
        phone = list_of_phones[i]
        print(i+1, ". ", return_str_of_the_phone(phone))

def Menu():

    list_of_phones = []

    list_of_phones = GeneratePhones(list_of_phones)
    while True:

        print("Choose from the following instructions:")
        print("Write down:")
        print(" 1. add and the manufacturer, the model and the price of the phone you want to add to the list")
        print(" 2. find and the manufacturer")
        print(" 3. increase and the manufacturer, the model and the new amount for increasing the price of the given phone")
        print(" 4. increase_percent and percent for updating the price of all phones with the given percent")

        option_chosen = input()
        instructions = option_chosen.split()

        if instructions[0] == "add":
            initial_length = len(list_of_phones)
            list_of_phones = add_phone_to_list_of_phones(list_of_phones, instructions)
            if initial_length == len(list_of_phones):
                print("The phone was not added to the list")
            else:
                print_list_of_phones(list_of_phones)
        elif instructions[0] == "find":
            list_of_phones_with_the_manufacturer_given = []
            list_of_phones_with_the_manufacturer_given = find_phone_with_given_manufacturer(list_of_phones, instructions)
            if len(list_of_phones_with_the_manufacturer_given) == 0:
                print("There is no phone which has this manufacturer")

            else:
                print_list_of_phones(list_of_phones_with_the_manufacturer_given)
        elif instructions[0] == "increase":
            found = False
            found = increase_price_of_given_phone(list_of_phones, instructions)
            if found == True:
                print_list_of_phones(list_of_phones)
            else:
                print("There is not a phone with given manufacturer and model")
        elif instructions[0] == "increase_percent":
            pass
        else:
            print("Invalid instruction")


def Start():
    Menu()

Start()