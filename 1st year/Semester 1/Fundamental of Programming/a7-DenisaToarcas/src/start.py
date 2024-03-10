from src.repository.student_repo import MemoryRepository, TextFileRepository, BinaryFileRepository
from src.services.student_services import StudentService
from src.ui.console import UI
from src.repository.student_repo import generate_students

repository = TextFileRepository()
student_list = []
student_list = generate_students()

for student in student_list:
    repository.add_element(student)

service = StudentService(repository)
console = UI(service)

console.start_ui()