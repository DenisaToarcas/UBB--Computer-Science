from domain.student import Student
from domain.student_validator import StudentValidator
from domain.grade import Grade
from domain.grade_validator import GradeValidator

from repo.student_repo import StudentRepo
from repo.grade_repo import GradeRepo

from controller.student_controller import StudentController
from controller.grade_controller import GradeController

from ui.console import UI

student_repo = StudentRepo()
grade_repo = GradeRepo()
student_validator = StudentValidator()
grade_validator = GradeValidator()

student_controller = StudentController(student_repo, student_validator, grade_repo)
grade_controller = GradeController(grade_repo, grade_validator)

ui = UI(student_controller, grade_controller)

ui.start_of_program()