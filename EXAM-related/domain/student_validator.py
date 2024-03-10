from domain.student import Student
from domain.validation_exceptions import ValidationException


class StudentValidator:
    def validate(self, student):
        if isinstance(student, Student) is False:
            raise ValidationException("Not a student type object!")
        _list_of_exceptions = []
        if len(student.name) == 0:
            _list_of_exceptions.append("Student introduced does not have a name!")
        if len(student.group) == 0:
            _list_of_exceptions.append("Student introduced does not have a group!")
        if len(_list_of_exceptions) != 0:
            raise ValidationException(_list_of_exceptions)
        return True


"""
student_1 = Student(1212, "ana", "917")
student_validator = StudentValidator()
student_2 = Student(1111, "", "910")

print(student_validator.validate(student_1))
print(student_validator.validate(student_2))
"""