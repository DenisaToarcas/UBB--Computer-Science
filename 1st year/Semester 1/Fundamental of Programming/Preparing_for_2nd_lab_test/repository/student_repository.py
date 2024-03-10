from domain.student import Student

from repository.repo_exceptions import RepositoryException

import random

class StudentRepository:
    def __init__(self, file_name="student.txt"):
        self.__file_name = file_name
        self.__students = []
        self.load_file()

    def load_file(self):
        """
                Load the students from a text file
        """
        # t - text file mode, r - reading

        students = []

        try:
            file_input = open(self.__file_name, "rt")

            students = file_input.readlines()

            file_input.close()
        except IOError:
            raise RepositoryException("Input file was not found!")

        for student in students:
            current_student = student.split()
            new_student = Student(int(current_student[0]), current_student[1], int(current_student[2]))
            self.add_student(new_student)

    def add_student(self, new_student: Student):
        if self.find(new_student.id) is not None:
            raise RepositoryException("Student with id: " + str(new_student.id) + " is already in list!")
        else:
            self.__students.append(new_student)

    def find(self, student_id):
        for student in self.__students:
            if student.id == student_id:
                return student

        return None

    def get_all_students_from_list(self):
        return self.__students

    def sort_students_in_descending_order(self):
        student_list = self.get_all_students_from_list()

        for i in range(0, len(student_list)):
            student = self.__students[i]
            for j in range(i+1, len(student_list)):
                second_student = self.__students[j]
                if student.playing_strength < second_student.playing_strength:
                    auxiliary = self.__students[i]
                    self.__students[i] = self.__students[j]
                    self.__students[j] = auxiliary

                    student = self.__students[i]

        return self.__students

    def get_student_from_list(self, student_id: int):
        for student in self.__students:
            if student.id == student_id:
                return student
        return None

    def closest_power_of_2(self):
        power_of_2 = 2
        while power_of_2 < len(self.__students):
            power_of_2 = 2*power_of_2

        return power_of_2

    def what_to_play(self):
        power_of_two = self.closest_power_of_2()
        if len(self.__students) == power_of_two:
            return self.play_tournament()
        else:
            return self.play_qualifications()

    def play_tournament(self):
        random.shuffle(self.__students)
        return self.__students

    def play_qualifications(self):
        players = []
        power_of_two = self.closest_power_of_2()
        power_of_two /= 2
        how_many_games_to_play = len(self.__students) - power_of_two
        how_many_students_to_play = 2*how_many_games_to_play

        index = len(self.__students) - 1
        while how_many_students_to_play != 0:
            players.append(self.__students[index])
            index = index - 1
            how_many_students_to_play -= 1

        random.shuffle(players)
        return players

    def remove_student_from_list(self, student: Student):
        self.__students.remove(student)

    def __repr__(self):
        return str(self)

    def __str__(self):
        list_of_students = ""
        for student in self.__students:
            list_of_students += student
            list_of_students += "\n"

    def __len__(self):
        return len(self.__students)


