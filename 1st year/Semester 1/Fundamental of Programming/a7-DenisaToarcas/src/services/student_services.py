from src.domain.student import student
from src.repository.student_repo import MemoryRepository
from src.domain.student_validator import StudentValidator

class StudentService:
    def __init__(self, repository: MemoryRepository):
        self._repository = repository

    def add_student(self, id: int, name: str, group: int):
        new_student = student(id, name, group)
        self._repository.add_element(new_student)

    def get_all_students(self):
        return self._repository.get_all()

    def delete_all_students_from_group(self, group: int):
        self._repository.delete_students_from_group(group)

    def undo(self):
        return self._repository.undo()