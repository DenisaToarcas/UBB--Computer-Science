from controller.student_controller import StudentController
from controller.grade_controller import GradeController

class UI:
    def __init__(self, student_controller:StudentController, grade_controller: GradeController):
        self.__student_controller = student_controller
        self.__grade_controller = grade_controller

    def menu(self):
        while True:
            try:
                print("Choose to:")
                print("1. Add a student to the course")
                print("2. Remove a student from course")
                print("3. Assign a lab problem to a student")
                print("4. Assign a lab to a group")
                print("0. End program")

                option = input(">>>")
                ADD_STUDENT = "1"
                REMOVE_STUDENT = "2"
                ASSIGN_LAB_PROBLEM = "3"
                ASSIGN_LAB_TO_GROUP = "4"
                END_PROGRAM = "0"

                if option == ADD_STUDENT:
                    try:
                        id = int(input("id: "))
                        name = input("name: ")
                        group = input("group: ")
                        self.__student_controller.add_element(id, name, group)
                    except Exception as exception:
                        print(exception)

                elif option == REMOVE_STUDENT:
                    try:
                        id = int(input("id: "))
                        self.__student_controller.remove_student(id)
                    except Exception as exception:
                        print(exception)

                elif option == ASSIGN_LAB_PROBLEM:
                    try:
                        id = int(input("id: "))
                        lab_no = int(input("laboratory's number: "))
                        problem = int(input("lab problem: "))
                        self.__student_controller.assignLab(id, lab_no, problem)
                    except Exception as exception:
                        print(exception)
                elif option == ASSIGN_LAB_TO_GROUP:
                    try:
                        group = input("group: ")
                        lab_no = int(input("laboratory's number: "))
                        self.__student_controller.assignLabGroup(group, lab_no)
                    except Exception as exception:
                        print(exception)
                elif option == END_PROGRAM:
                    print("BYE BYE little spoon!")
                    break
            except ValueError:
                print("Invalid input!")

    def start_of_program(self):
        self.menu()