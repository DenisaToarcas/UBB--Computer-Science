import random
def GeneratePhones(list_of_phones : list):
    #this function generates 5 random phones and puts them in the list
    manufacturers = ["Samsung", "Huawei", "Apple", "Nokia", "LC"]
    models = ["Note1", "XC200", "Galaxy", "P4020", "P2920"]
    prices = ["3000", "3500", "4000", "4500", "5000"]

    for i in range(0, 5):
        manufacturer = random.choice(manufacturers)
        model = random.choice(models)
        price = random.choice(prices)

        phone = [manufacturer, model, price]
        list_of_phones.append(phone)

    return list_of_phones

def add_phone_to_list_of_phones(list_of_phones : list, instructions):
    manufacturer = instructions[1]
    model = instructions[2]
    price = instructions[3]

    if len(manufacturer) < 3 or len(model) < 3 or len(price) < 3:
        return list_of_phones
    else:
        phone = [manufacturer, model, price]
        list_of_phones.append(phone)
        return list_of_phones

def find_phone_with_given_manufacturer(list_of_phones : list, instructions):
    list_of_phones_with_manufacturer = []

    manufacturer = instructions[1]
    for i in range(0, len(list_of_phones)):
        phone = list_of_phones[i]
        if phone[0] == manufacturer:
            list_of_phones_with_manufacturer.append(phone)

    return list_of_phones_with_manufacturer

def get_manufacturer_of_the_phone(phone):
    return phone[0]

def get_model_of_the_phone(phone):
    return phone[1]

def get_price_of_the_phone(phone):
    return phone[2]

def return_str_of_the_phone(phone):
    manufacturer = get_manufacturer_of_the_phone(phone)
    model = get_model_of_the_phone(phone)
    price = get_price_of_the_phone(phone)

    return str(manufacturer) + " " + str(model) + " " + str(price)

def increase_price_of_given_phone(list_of_phones, instructions):
    manufacturer = instructions[1]
    model = instructions[2]
    new_amount = instructions[3]
    found = False

    for i in range(0, len(list_of_phones)):
        phone = list_of_phones[i]
        if (phone[0] == manufacturer and phone[1] == model):
            price = int(get_price_of_the_phone(phone))
            amount = int(new_amount)
            final_price = price + amount
            phone[2] = str(final_price)
            found = True
            break

    return found