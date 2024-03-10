"""
 Compute the sum of even elements in the given list
 input:
 l - the list of numbers
 output:
 The sum of the even elements in the list

 Raises TypeError if parameter l is not a Python list
 Raises ValueError if the list does not contain even numbers
"""
l = [1, 2, 3, 4, 5, 6]
l_for_value_error = [1, 3, 5]
l_for_type_error = "ana"


def sum(l):
    try:
        if not isinstance(l, list):
            raise TypeError("parameter l is not a Python list")
        else:
            s = 0
            done = False
            for i in range(len(l)):
                if l[i] % 2 == 0:
                    s = s + l[i]
                    done = True
            if done is True:
                return s
            else:
                raise ValueError("The list does not contain even numbers")
    except Exception as error:
        return error


print(sum(l))
print(sum(l_for_value_error))
print(sum(l_for_type_error))


def function(n):
    d = 2
    while (d < n - 1) and n % d > 0:
        d += 1
        # print(d)
    return d >= n - 1


print(function(2))
print(function(7))
print(function(15))
print(function(19))
""" Because we have that n % d > 0 and d = 2 at the beginning, this function will return False for the even numbers"""
"""THIS FUNCTION VERIFIES IF N IS A PRIME NUMBER"""
"""
import unittest

class TestFunction(unittest.TestCase):

    def test_function1(self):
        self.assertEqual(function(2), True)
        self.assertEqual(function(3), True)
        self.assertEqual(function(14), False)
"""
from typing import List


class Product:
    def __init__(self, name: str, type: str, price: float):
        self.name = name
        self.type = type
        self.price = price

    def __str__(self):
        return self.name + " " + self.type + " " + str(self.price)

    def __repr__(self):
        return str(self)


class ProductList:
    def __init__(self):
        self.products = []

    def add_product(self, product: Product):
        self.products.append(product)

    def get_all(self):
        return self.products

    def __iter__(self):
        self.index = -1
        return self

    def __next__(self):
        self.index += 1
        if self.index >= len(self.products):
            raise StopIteration
        return self.products[self.index]

    def __str__(self):
        list_of_products = ""
        for product in self.products:
            list_of_products += str(product)
            list_of_products += "\n"

        return list_of_products


def sort_products(products: List[Product], key=lambda x: x.name, reverse=False):
    products.sort(key=key, reverse=reverse)
    return products

def sort_products_with_sorted(products: List[Product]):
    sorted_list = sorted(products, key=lambda x: (x.name, -x.price))
    return sorted_list

product_list = ProductList()
product_list.add_product(Product("apple", "fruit", 1.5))
product_list.add_product(Product("apple", "fruit", 1.09))
product_list.add_product(Product("amandina", "cake", 0.7))
product_list.add_product(Product("banana", "fruit", 2.5))
product_list.add_product(Product("carrot", "vegetable", 0.5))
product_list.add_product(Product("donut", "bakery", 2.0))
product_list.add_product(Product("egg", "diary", 0.5))
product_list.add_product(Product("flour", "grocery", 0.75))
product_list.add_product(Product("grapes", "fruit", 3.0))
product_list.add_product(Product("honey", "grocery", 5.0))

print(product_list)
print(sort_products(product_list.get_all(), key=lambda x: x.name, reverse=False))
print(sort_products_with_sorted(product_list.get_all()))


def permute_increasing_decreasing(n):
    def is_valid(perm, max_index):
        for i in range(max_index):
            if perm[i] >= perm[max_index]:
                return False
        for i in range(max_index + 1, n):
            if perm[i] <= perm[max_index]:
                return False
        return True

    def backtrack(perm, max_index):
        if max_index == n:
            result.append(perm[:])
            return

        for i in range(n):
            if i not in perm:
                perm[max_index] = i
                if is_valid(perm, max_index):
                    backtrack(perm, max_index + 1)
                perm[max_index] = -1

    result = []
    backtrack([-1] * n, 0)
    return result

print(permute_increasing_decreasing(3))
