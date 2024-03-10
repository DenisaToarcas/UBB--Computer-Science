from game import Game

class UI:
    def __init__(self, game: Game):
        self.__game = game

    def display_game_board(self):
        print(str(self.__game.display_game_board()))

    def menu(self):
        self.display_game_board()
        while True:
            try:
                do_command = input(">>>")
                list_of_commands = do_command.split()

                if list_of_commands[0] == "place":
                    if len(list_of_commands) != 3:
                        raise Exception("Invalid command!!!")
                    self.__game.place_on_board(list_of_commands[1], list_of_commands[2])
                    self.display_game_board()

                elif list_of_commands[0] == "save":
                    self.__game.save_state(list_of_commands[1])

                else:
                    raise Exception("Invalid command!!!")
            except Exception as error:
                print(error)