from src.Controller import ControllGame

class UI:
    def __init__(self, game_controller: ControllGame):
        self.__game_controller = game_controller

    def main(self):
        print(str(self.__game_controller.get_word_to_play_shuffled()))
        score = self.__game_controller.get_score()
        while True:
            try:
                option_chosen = input(">>>")
                commands = option_chosen.split()

                if commands[0] == "swap":
                    if len(commands) != 6:
                        raise ValueError("Invalid command!")
                    else:
                        for i in range(1, 6):
                            if commands[i] != '-':
                                if commands[i] < '0':
                                    raise ValueError("Invalid command!")

                        word_to_be_swapped_1 = int(commands[1])
                        letter_1_to_be_swapped = int(commands[2])

                        word_to_be_swapped_2 = int(commands[4])
                        letter_2_to_be_swapped = int(commands[5])
                        print(self.__game_controller.swap_letters_of_words(word_to_be_swapped_1, letter_1_to_be_swapped,
                                                                           word_to_be_swapped_2, letter_2_to_be_swapped))
                        score = score - 1
                        print("[score is: " + str(score) + "]")

                elif commands[0] == "undo":
                    pass
                else:
                    raise ValueError("Invalid command!")

            except Exception as exception:
                print(exception)

