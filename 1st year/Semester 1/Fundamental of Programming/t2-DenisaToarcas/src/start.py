from services import student_services
from repository import student_repository
from domain import student_validator
from ui import Ui

student_repo = student_repository()
_student_validator = student_validator()
student_services = student_services(student_repo, _student_validator)

ui = Ui(student_services)

Ui.menu(ui)