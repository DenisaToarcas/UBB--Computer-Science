from src.services.student_services import StudentService

class UI:
    def __init__(self, service: StudentService):
        self._service = service

    def menu(self):
        print()
        print("Choose from the following options:")
        print("1.Add a student. Student data is read from the console.")
        print("2.Display the list of students.")
        print("3.Filter the list so that students in a given group (read from the console) are deleted from the list.")
        print("4.Undo the last operation that modified program data. This step can be repeated.")
        print("5.Exit the program")

    def start_ui(self):
        while True:
            try:
                self.menu()
                option_chosen = int(input("Please introduce the option here:"))
                ADD_STUDENT_OPTION = 1
                DISPLAY_LIST_OF_STUDENTS_OPTION = 2
                DELETE_STUDENTS_FROM_GROUP_OPTION = 3
                UNDO_OPTION = 4
                EXIT_PROGRAM = 5

                if option_chosen == ADD_STUDENT_OPTION:
                    id = int(input("Please introduce the id of the student:"))
                    name = input("Please introduce the name of the student:")
                    group = int(input("Please introduce the group of the student:"))

                    self._service.add_element(id, name, group)
                    self.student_list = self._service.get_all_students()

                elif option_chosen == DISPLAY_LIST_OF_STUDENTS_OPTION:
                    self.student_list = self._service.get_all_students()
                    for student in self.student_list:
                        print(repr(student))

                elif option_chosen == DELETE_STUDENTS_FROM_GROUP_OPTION:
                    group_from_which_to_delete_students = int(input("Introduce the group from which you want to delete students:"))
                    self._service.delete_all_students_from_group(group_from_which_to_delete_students)

                elif option_chosen == UNDO_OPTION:
                    self._service.undo()

                elif option_chosen == EXIT_PROGRAM:
                    print("The program ended successfully! BYE BYE :))))")
                    break
                else:
                    print("Invalid option introduced!")

            except ValueError:
                print("Invalid input introduced!")
