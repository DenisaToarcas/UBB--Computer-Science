from board import Board
from game import Game
from computer_player import ComputerPlayer

class UI:
    def __init__(self, game: Game):
        self.__game = game

    def menu(self):
        while True:
            try:
                first_to_play = None
                print(self.__game.display_board())

                print("Select to play with X or O:")
                symbol_chosen = input(">>>")

                if symbol_chosen == 'X':
                    first_to_play = "human"
                    self.menu_human()

                if symbol_chosen == 'O':
                    first_to_play = "computer"
                    self.menu_computer()

                for i in range(0, 3):
                    if first_to_play == "human":
                        self.menu_human()
                        if self.__game.is_game_won() is not False:
                            break

                    elif first_to_play == "computer":
                        self.menu_computer()
                        if self.__game.is_game_won() is not False:
                            break

                if self.__game.is_game_won() == 'X' and first_to_play == "human":
                    print("Winner of the game is: HUMAN")
                    break
                elif self.__game.is_game_won() == 'X' and first_to_play == "computer":
                    print("Winner of the game is: COMPUTER")
                    break
                elif self.__game.is_game_won() == 'O' and first_to_play == "human":
                    print("Winner of the game is: COMPUTER")
                    break
                elif self.__game.is_game_won() == 'O' and first_to_play == "computer":
                    print("Winner of the game is: HUMAN")
                    break
                else:
                    self.movement_phase(first_to_play)

            except Exception as e:
                print(e)

    def menu_human(self):
        print("Choose where to place your X on table:")
        row = input("row: ")
        column = input("column: ")

        if row != '0' and row != '1' and row != '2':
            while row != '0' and row != '1' and row != '2':
                print("Invalid row introduced!")
                row = input("row: ")
        if column != '0' and column != '1' and column != '2':
            while column != '0' and column != '1' and column != '2':
                print("Invalid column introduced!")
                column = input("column: ")

        self.__game.move_human(int(row), int(column), 'X')
        self.__game.update_the_board_for_computer()
        row, column = self.__game.get_moves_of_computer()
        self.__game.move_computer(row, column, 'O')
        print(self.__game.display_board())

    def menu_computer(self):
        self.__game.move_computer(1, 1, 'X')

        print("Choose where to place your X on table:")
        row = input("row: ")
        column = input("column: ")

        if row != '0' and row != '1' and row != '2':
            while row != '0' and row != '1' and row != '2':
                print("Invalid row introduced!")
                row = input("row: ")
        if column != '0' and column != '1' and column != '2':
            while column != '0' and column != '1' and column != '2':
                print("Invalid column introduced!")
                column = input("column: ")

        self.__game.move_human(int(row), int(column), 'O')
        self.__game.update_the_board_for_computer()
        print(self.__game.display_board())

    def movement_phase(self, first_to_play: str):
        while self.__game.is_game_won() is False:
            if first_to_play == "human":
                print("Introduce:")
                row_from_where = input("row_from_where: ")
                column_from_where = input("column_from_where: ")
                new_row = input("new_row: ")
                new_column = input("new_column: ")

                if row_from_where != '0' and row_from_where != '1' and row_from_where != '2':
                    while row_from_where != '0' and row_from_where != '1' and row_from_where != '2':
                        print("Invalid row from which to move!")
                        row_from_where = input("row_from_where: ")

                elif column_from_where != '0' and column_from_where != '1' and column_from_where != '2':
                    while column_from_where != '0' and column_from_where != '1' and column_from_where != '2':
                        print("Invalid column from which to move!")
                        column_from_where = input("column_from_where: ")

                elif new_row != '0' and new_row != '1' and new_row != '2':
                    while new_row != '0' and new_row != '1' and new_row != '2':
                        print("Invalid row where to move!")
                        new_row = input("new_row: ")

                elif new_column != '0' and new_column != '1' and new_column != '2':
                    while new_column != '0' and new_column != '1' and new_column != '2':
                        print("Invalid column where to move!")
                        new_column = input("new_column: ")

                self.__game.move_elements_on_board(int(row_from_where), int(column_from_where), int(new_row), int(new_column), 'X')
                self.__game.update_the_board_for_computer()
                self.__game.get_movements_of_computer('O')
                print(self.__game.display_board())

            else:
                self.__game.get_movements_of_computer('X')
                print("Introduce:")
                row_from_where = input("row_from_where: ")
                column_from_where = input("column_from_where: ")
                new_row = input("new_row: ")
                new_column = input("new_column: ")

                if row_from_where != '0' and row_from_where != '1' and row_from_where != '2':
                    while row_from_where != '0' and row_from_where != '1' and row_from_where != '2':
                        print("Invalid row from which to move!")
                        row_from_where = input("row_from_where: ")

                elif column_from_where != '0' and column_from_where != '1' and column_from_where != '2':
                    while column_from_where != '0' and column_from_where != '1' and column_from_where != '2':
                        print("Invalid column from which to move!")
                        column_from_where = input("column_from_where: ")

                elif new_row != '0' and new_row != '1' and new_row != '2':
                    while new_row != '0' and new_row != '1' and new_row != '2':
                        print("Invalid row where to move!")
                        new_row = input("new_row: ")

                elif new_column != '0' and new_column != '1' and new_column != '2':
                    while new_column != '0' and new_column != '1' and new_column != '2':
                        print("Invalid column where to move!")
                        new_column = input("new_column: ")

                self.__game.move_elements_on_board(int(row_from_where), int(column_from_where), int(new_row),
                                                   int(new_column), 'O')
                self.__game.update_the_board_for_computer()
                print(self.__game.display_board())

            if self.__game.is_game_won() == 'X' and first_to_play == "human":
                print("Winner of the game is: HUMAN")
                break
            elif self.__game.is_game_won() == 'X' and first_to_play == "computer":
                print("Winner of the game is: COMPUTER")
                break
            elif self.__game.is_game_won() == 'O' and first_to_play == "human":
                print("Winner of the game is: COMPUTER")
                break
            elif self.__game.is_game_won() == 'O' and first_to_play == "computer":
                print("Winner of the game is: HUMAN")
                break

game_board = Board()
computer = ComputerPlayer(game_board)
game = Game(game_board, computer)
ui = UI(game)

ui.menu()