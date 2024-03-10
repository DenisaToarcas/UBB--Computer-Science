from domain.grade import Grade
from repo.RepoExceptions import RepoExceptions


class GradeRepo:
    def __init__(self, file_name="grades.txt"):
        self.__grades = []
        self.__file_name = file_name
        self.load_file()

    def load_file(self):
        file_input = open(self.__file_name, "rt")
        grades = file_input.readlines()
        file_input.close()

        for line in grades:
            current_info = line.split()
            studentID = int(current_info[0])
            laboratory_number = int(current_info[1])
            laboratoryProblem = int(current_info[2])
            value = int(current_info[3])
            new_grade = Grade(studentID, laboratory_number, laboratoryProblem, value)

            self.add_grades(new_grade)

    def add_grades(self, new_grade: Grade):
        self.__grades.append(new_grade)
        self.save_file()

    def save_file(self):
        file_output = open(self.__file_name, "wt")
        for grade_in_list in self.__grades:
            file_output.write(str(grade_in_list))
            file_output.write("\n")
        file_output.close()

    def get_all_info_about_student(self, studentID: int):
        """
        :param studentID: This function returns whatever info it finds for a specific student
        :return:
        """
        info_about_student = []
        for grade in self.__grades:
            if grade.studentID == studentID:
                info_about_student.append(grade)

        return info_about_student

    def get_all(self):
        return self.__grades