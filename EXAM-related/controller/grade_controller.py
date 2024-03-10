from domain.grade import Grade
from repo.grade_repo import GradeRepo
from domain.grade_validator import GradeValidator


class GradeController:
    def __init__(self, grade_repo: GradeRepo, grade_validator: GradeValidator):
        self.__grade_repo = grade_repo
        self.__grade_validator = grade_validator

    def grade(self, studentID: int, lab_no: int, grade: int):

        student_info_list = self.__grade_repo.get_all_info_about_student(studentID)

        for element in student_info_list:
            if element.laboratory_number == lab_no:
                self.__grade_validator.validate(Grade(studentID, lab_no, element.laboratoryProblem, grade))
                element.value = grade
                self.__grade_repo.add_grades(element)

    def display_all(self):
        return self.__grade_repo.get_all()
