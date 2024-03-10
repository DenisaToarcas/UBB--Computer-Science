
from domain import student
from RepoExceptions import RepoException
class student_repository:
    def __init__(self, file_name="student.txt", file_name_output="student_output.txt"):
        self.__file_name = file_name
        self.__file_name_output = file_name_output
        self.__students = []
        self.load_file()

    def load_file(self):
        file_input = open(self.__file_name, "rt")
        students = file_input.readlines()
        file_input.close()

        for _student in students:
            info = _student.split()
            student_name = info[1] + " " + info[2]
            student_to_add = student(int(info[0]), student_name, int(info[3]), int(info[4]))
            self.add_student(student_to_add)

    def save_file(self):
        file_output = open(self.__file_name_output, "wt")
        file_output.write(str(self.__students))
        file_output.close()

    def add_student(self, new_student: student):
        if new_student.id in self.__students:
            raise RepoException("Student already in list!")
        else:
            self.__students.append(new_student)
            self.save_file()

    def get_all_students_decreasing_order(self):
        self.decreasing_order_of_grades()
        return self.__students

    def get_grade(self, _student: student):
        return _student.grade

    def decreasing_order_of_grades(self):
        for i in range(0, len(self.__students)):
            for j in range(i+1, len(self.__students)):
                if self.get_grade(self.__students[i]) < self.get_grade(self.__students[j]):
                    auxiliary = self.__students[i]
                    self.__students[i] = self.__students[j]
                    self.__students[j] = auxiliary


    def get_all_students(self):
        return self.__students

    def __str__(self):
        list_of_students = ""
        for _student in self.__students:
            list_of_students += _student
            list_of_students += "\n"
        return list_of_students