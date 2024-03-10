from repository import student_repository
from domain import student_validator
from domain import student


class student_services:
    def __init__(self, student_repo: student_repository, student_validator: student_validator):
        self.__student_repo = student_repo
        self.__student_validator = student_validator

    def add_student(self, id: int, name: str, attendance_count: int, grade: int):
        _new_student = student(id, name, attendance_count, grade)
        self.__student_validator.validatde(_new_student)
        self.__student_repo.add_student(_new_student)

    def display_students_decreasing_order_of_grades(self):
        return self.__student_repo.get_all_students_decreasing_order()

    def get_all_students_from_list(self):
        return self.__student_repo.get_all_students()
