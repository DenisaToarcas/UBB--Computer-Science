from services.student_services import StudentServices



class UI:
    def __init__(self, student_services: StudentServices):
        self.__student_services = student_services

    def start_program(self):
        list_of_students = self.__student_services.get_all_students_from_list()
        for student in list_of_students:
            print(student)

        print()

        list_of_students = self.__student_services.sort_students_in_descending_order()
        for student in list_of_students:
            print(student)

        print()

        while len(self.__student_services.get_all_students_from_list()) != 1:
            """
                    If self.__student_services.what_to_play() is True it means that we are playing a tournament
                    Otherwise we play qualifications!!!
            """
            if self.__student_services.what_to_play() is True:
                print("\nLast " + str(len(self.__student_services.get_all_students_from_list())))
                student_list = self.__student_services.get_all_students_from_list()
                for student in list_of_students:
                    print(student)
                print()

                i = 0

                while i != len(student_list):
                    print("First player is: " + str(student_list[i]))
                    print("Second player is: " + str(student_list[i+1]))

                    print("Write down 1 for the first player to win and 2 for the second one!")
                    which_one_to_win = input("Who wins: ")
                    print()

                    FIRST_PLAYER_WINS = "1"
                    SECOND_PLAYER_WINS = "2"

                    if which_one_to_win == FIRST_PLAYER_WINS:
                        self.__student_services.remove_student_from_list(student_list[i+1])
                    elif which_one_to_win == SECOND_PLAYER_WINS:
                        self.__student_services.remove_student_from_list(student_list[i])

                    i += 1

            else:
                print("\nQualifications")
                student_list = self.__student_services.play_qualifications()
                for student in student_list:
                    print(student)
                print()

                i = 0

                while i != len(student_list):
                    print("First player is: " + str(student_list[i]))
                    print("Second player is: " + str(student_list[i + 1]))

                    print("Write down 1 for the first player to win and 2 for the second one!")
                    which_one_to_win = input("Who wins: ")
                    print()

                    FIRST_PLAYER_WINS = "1"
                    SECOND_PLAYER_WINS = "2"

                    if which_one_to_win == FIRST_PLAYER_WINS:
                        self.__student_services.remove_student_from_list(student_list[i+1])
                    elif which_one_to_win == SECOND_PLAYER_WINS:
                        self.__student_services.remove_student_from_list(student_list[i])

                    i += 2

        winner = self.__student_services.get_all_students_from_list()
        print("Winner of the game is: " + str(winner))