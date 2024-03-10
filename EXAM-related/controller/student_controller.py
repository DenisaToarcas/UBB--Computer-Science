from domain.grade import Grade
from domain.student import Student
from domain.student_validator import StudentValidator
from repo.student_repo import StudentRepo
from repo.grade_repo import GradeRepo

class StudentController:
    def __init__(self, student_repo: StudentRepo, student_validator: StudentValidator, grade_repo: GradeRepo):
        self.__student_repo = student_repo
        self.__grade_repo = grade_repo
        self.__student_validator = student_validator

    def add_student(self, id: int, name: str, group: str):
        new_student = Student(id, name, group)
        self.__student_validator.validate(new_student)

        self.__student_repo.add_element(new_student)

    def remove_student(self, studentID: int):
        student_info = self.__grade_repo.get_all_info_about_student(studentID)
        if len(student_info) != 0:
            for i in range(0, len(student_info)):
                element = student_info[i]
                if element.value == 0:
                    self.__student_repo.remove_student_from_list(studentID)
                    break
        else:
            self.__student_repo.remove_student_from_list(studentID)

    def display_all_students(self):
        return self.__student_repo.get_all_students()

    def assignLab(self, studentID: int, labNo: int, labProblem: int):
        if self.__student_repo.find_student(studentID) is not None:
            info_about_student = self.__grade_repo.get_all_info_about_student(studentID)

            if len(info_about_student) != 0:
                for i in range(0, len(info_about_student)):
                    element = info_about_student[i]
                    if element.laboratory_number == labNo:
                        raise ValueError("Already assigned a problem for this lab!")
                self.__grade_repo.add_grades(Grade(studentID, labNo, labProblem, 0))
            else:
                self.__grade_repo.add_grades(Grade(studentID, labNo, labProblem, 0))
        else:
            raise Exception("This student is not part of the list!")

    def get_students_from_group(self, group_assigned: str):
        list_of_all_students = self.__student_repo.get_all_students()
        students_from_given_group = []

        for student in list_of_all_students:
            if student.group == group_assigned:
                students_from_given_group.append(student)

        if len(students_from_given_group) != 0:
            return students_from_given_group
        else:
            raise Exception("There is no student in this group!")

    def assignLabGroup(self, group: str, labNo: int):
        students_to_assign = self.get_students_from_group(group)
        problem_to_assign = 1

        for _student in students_to_assign:
            _info_about_student = self.__grade_repo.get_all_info_about_student(_student.id)
            already_assigned = False

            if len(_info_about_student) != 0:
                for i in range(0, len(_info_about_student)):
                    element = _info_about_student[i]
                    if element.laboratory_number == labNo:
                        already_assigned = True

                if already_assigned is False:
                    self.__grade_repo.add_grades(Grade(_student.id, labNo, problem_to_assign, 0))
                    problem_to_assign = problem_to_assign + 1
            else:
                self.__grade_repo.add_grades(Grade(_student.id, labNo, problem_to_assign, 0))
                problem_to_assign = problem_to_assign + 1
