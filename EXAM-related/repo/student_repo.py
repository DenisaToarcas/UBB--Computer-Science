from domain.student import Student
from repo.RepoExceptions import RepoExceptions

class StudentRepo:
    def __init__(self, file_name="students.txt"):
        self.__students = []
        self.__file_name = file_name
        self.load_file()

    def __repr__(self):
        return str(self)

    def __str__(self):
        list_of_students = ""
        for student in self.__students:
            list_of_students += str(student)
            list_of_students += "\n"
        return list_of_students

    def load_file(self):
        file_input = open(self.__file_name, "rt")
        students = file_input.readlines()
        file_input.close()

        for line in students:
            info_student = line.split()
            id = int(info_student[0])
            name = info_student[1]
            group = info_student[2]
            new_student = Student(id, name, group)

            self.add_student(new_student)

    def add_student(self, new_student: Student):
        if new_student.id in self.__students:
            raise RepoExceptions("Student already in list!")
        else:
            self.__students.append(new_student)
            self.save_file()

    def save_file(self):
        file_output = open(self.__file_name, "wt")
        for student_in_list in self.get_all_students():
            file_output.write(str(student_in_list))
            file_output.write("\n")
        file_output.close()

    def get_all_students(self):
        return self.__students

    def find_student(self, studentID: int):
        for student in self.__students:
            if student.id == studentID:
                return student
        return None

    def remove_student_from_list(self, studentID: int):
        if self.find_student(studentID) is not None:
            self.__students.remove(self.find_student(studentID))
            self.save_file()
        else:
            raise RepoExceptions("Student not in list!")



"""
student = Student(12121221, "ana", "917")
studentrepo = StudentRepo()
studentrepo.add_student(student)
print(studentrepo.get_all_students())
"""