from repository.student_repository import StudentRepository
from domain.student import StudentValidator
from domain.student import Student


class StudentServices:
    def __init__(self, student_repo: StudentRepository, student_validator: StudentValidator):
        self.__student_repo = student_repo
        self.__student_validator = student_validator

    def add_student(self, id: int, name: str, strength: int):
        new_student = Student(id, name, strength)
        self.__student_validator.validate(new_student)
        self.__student_repo.add_element(new_student)

    def get_all_students_from_list(self):
        return self.__student_repo.get_all_students_from_list()

    def sort_students_in_descending_order(self):
        return self.__student_repo.sort_students_in_descending_order()

    def what_to_play(self):
        list_of_players = self.__student_repo.what_to_play()

        if len(list_of_players) == len(self.__student_repo.get_all_students_from_list()):
            return True
        else:
            return False

    def play_qualifications(self):
        return self.__student_repo.play_qualifications()

    def remove_student_from_list(self, student: Student):
        self.__student_repo.remove_student_from_list(student)

