"""
import unittest

def function(a, b, c):
    a = a+1
    b.append(3)
    c = c + [3]
    CONCATENATES 2 VECTORS, but does NOT CHANGE them in MEMORY
    return c

a = 7
b = [1, 2]
c = [1, 2]
print(function(a, b, c))
print(a, b, c)

def f(l):
    if (l == None):
        raise ValueError()
    for e in l:
        if e % 2 == 0:
            return True

    return False

class Tests(unittest.TestCase):
    def test1(self):
       l = [1, 2, 4]
       self.assertEqual(f(l), True)

    def test2(self):
        l = None
        try:
            f(l)
        except ValueError:
            self.assertRaises(ValueError)
        else:
            assert False

    DIVIDE ET IMPERA


def sum_of_even_numbers(list_of_no: list):
    if len(list_of_no) != 1:
        mid = len(list_of_no) // 2
        left_no = list_of_no[:mid]
        right_no = list_of_no[mid:]

        return sum_of_even_numbers(left_no) + sum_of_even_numbers(right_no)

    else:
        if list_of_no[0] % 2 == 0:
            return list_of_no[0]
        return 0

class test_sum_even(unittest.TestCase):

    def test_list_without_even_no(self):
        list = [1, 3, 5, 7]
        self.assertEqual(sum_of_even_numbers(list), 0)

    def test_list_with_only_even_no(self):
        list = [2, 4, 6]
        self.assertEqual(sum_of_even_numbers(list), 12)

    def test_list_with_both_even_and_odds(self):
        list = [1, 2, 3]
        self.assertEqual(sum_of_even_numbers(list), 2)


a = 1
b = [str(a), 1]
c = (a, str(b[1]))

print(a, b, c)

print(type(a) == type(c))
"""

class SpareMatrix:
    def __init__(self, no_of_rows: int, no_of_columns: int):
        self.__no_of_rows = no_of_rows
        self.__no_of_columns = no_of_columns
        self.__sparse_matrix = []
        self.__index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.__index >= len(self.__sparse_matrix):
            raise StopIteration
        result = self.__sparse_matrix[self.__index]
        self.__index += 1
        return result

    def __len__(self):
        return len(self.__sparse_matrix)

    def set(self, row: int, column: int, value: int):
        if row >= self.__no_of_rows or column >= self.__no_of_columns:
            raise ValueError()
        found = False
        for i in range(0, len(self.__sparse_matrix)):
            if self.__sparse_matrix[i][0] == row and self.__sparse_matrix[i][1] == column:
                found = True
                if value != 0:
                    self.__sparse_matrix[i][2] = value
                else:
                    self.__sparse_matrix.remove(self.__sparse_matrix[i])
        if found is False and value != 0:
            self.__sparse_matrix.append([row, column, value])

    def get(self, row: int, column: int):
        for i in range(0, len(self.__sparse_matrix)):
            if self.__sparse_matrix[i][0] == row and self.__sparse_matrix[i][1] == column:
                return self.__sparse_matrix[i][2]

    def __repr__(self):
        return str(self)

    def __str__(self):
        matrix_to_print = ""
        for i in range(0, self.__no_of_rows):
            if i != 0:
                matrix_to_print = matrix_to_print + "\n"
            for j in range(0, self.__no_of_columns):
                found = False
                for k in range(0, len(self.__sparse_matrix)):
                    if self.__sparse_matrix[k][0] == i and self.__sparse_matrix[k][1] == j:
                        matrix_to_print = matrix_to_print + str(self.__sparse_matrix[k][2]) + " "
                        found = True
                        break
                if found is False:
                    matrix_to_print = matrix_to_print + "0 "
        return matrix_to_print



m1 = SpareMatrix(3, 3)
m1.set(1, 1, 2)
m1.set(2, 2, 4)
print(m1)
try:
    m1.set(3, 3, 99)
except Exception as e:
    print(type(e))

m1.set(1, 1, m1.get(1, 1) + 1)
print()
print(m1)


