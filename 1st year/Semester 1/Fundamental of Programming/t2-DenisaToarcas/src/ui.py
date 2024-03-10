from services import student_services

class Ui:
    def __init__(self, student_services: student_services):
        self.__student_service = student_services

    def menu(self):
        while True:
            print()
            print("Choose from the following:")
            print(" 1.add student\n 2.display all students in decreasing order of their grade\n 3.give bonuses\n 4. display all students")
            option_chosen = input("Option:")

            add_student = "1"
            display_grades = "2"
            bonuses = "3"
            display_string = "4"

            if option_chosen == add_student:
                id = int(input("id:"))
                name = input("name:")
                attendance_count = int(input("attendance_count:"))
                grade = int(input("grade:"))

                self.__student_service.add_student(id, name, attendance_count, grade)
                print(str(self.__student_service.get_all_students_from_list()))

            elif option_chosen == display_grades:
                print(str(self.__student_service.display_students_decreasing_order_of_grades()))

            elif option_chosen == bonuses:
                pass

            elif option_chosen == display_string:
                pass
