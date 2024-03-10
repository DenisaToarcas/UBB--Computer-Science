from domain.grade import Grade
from domain.validation_exceptions import ValidationException
class GradeValidator:
    def validate(self, grade):
        if isinstance(grade, Grade) is False:
            raise ValidationException("Not a grade type object!")
        _list_of_exceptions = []
        if grade.laboratoryProblem < 1 or grade.laboratoryProblem > 20:
            _list_of_exceptions.append("The problem to be assigned is not in list = 1 to 20!")
        if grade.value < 1 or grade.value > 10:
            _list_of_exceptions.append("The grade given is not a valid one! Not between 1 and 10!")
        if len(_list_of_exceptions) != 0:
            raise ValidationException(_list_of_exceptions)
