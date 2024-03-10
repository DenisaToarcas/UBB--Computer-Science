from src import validation_errors
from validation_errors import validation_errors
class student:
    def __init__(self, id: int, name: str, attendance_count: int, grade: int):
        self.__student_id = id
        self.__attendance_count = attendance_count
        self.__name = name
        self.__grade = grade

    @property
    def id(self):
        return self.__student_id
    @id.setter
    def id(self, new_id: int):
        self.__student_id = new_id

    @property
    def name(self):
        return self.__name

    @property
    def attendance_count(self):
        return self.__attendance_count

    @attendance_count.setter
    def attendance_count(self, new_attendance_count: int):
        self.__attendance_count = new_attendance_count

    @property
    def grade(self):
        return self.__grade

    @grade.setter
    def grade(self, new_grade: int):
        self.__grade = new_grade

    def __repr__(self):
        return str(self)
    def __str__(self):
        return str(self.__student_id) + " " + self.__name + " " + str(self.__attendance_count) + " " + str(self.__grade)

class student_validator:
    def validatde(self, _student):
        if isinstance(_student, student) is False:
            raise validation_errors("Can't validate a non_student type of object!")

        if len(_student.name) < 7:
            raise validation_errors("Name is invalid!")

        if _student.attendance_count < 0:
            raise validation_errors("Attendance count is negative!")

        if _student.grade < 0 or _student.grade > 10:
            raise validation_errors("Student grade is invalid!")
