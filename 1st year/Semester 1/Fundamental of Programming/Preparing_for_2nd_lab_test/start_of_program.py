from repository.student_repository import StudentRepository
from services.student_services import StudentServices
from ui.console import UI
from domain.student import StudentValidator

student_repo = StudentRepository()
student_validator = StudentValidator()
student_services = StudentServices(student_repo, student_validator)
console = UI(student_services)

console.start_program()