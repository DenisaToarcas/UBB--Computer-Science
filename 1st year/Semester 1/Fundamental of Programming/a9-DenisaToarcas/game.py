from board import Board
from computer_player import ComputerPlayer


class Game:
    def __init__(self, game_board: Board, computer_player: ComputerPlayer):
        self.__game_board = game_board
        self.__computer_player = computer_player
        self.__human_moves = []

    def create_board(self, number_of_rows: int, number_of_columns: int):
        self.__game_board = Board(number_of_rows, number_of_columns)

    def display_board(self):
        return str(self.__game_board)

    def is_move_on_board(self, row: int, column: int):
        return self.__game_board.is_move_on_board(row - 1, column - 1)

    def move_human(self, row: int, column: int):
        """if self.__game_board.is_board_full() is True:
            return False"""
        self.__game_board.make_move_on_board(row, column, symbol='O')
        self.__human_moves.append([row, column])
        """return True"""

    def get_mirror(self):
        """Function that returns the row and column that represent the mirrored move of the player
        (strategy used by AI when it is the one to make the first move on an odd board)"""
        [row, column] = self.__human_moves.pop()

        numbers_of_rows = self.__game_board.get_rows()
        numbers_of_columns = self.__game_board.get_columns()

        if self.__game_board.is_move_on_board(numbers_of_rows - row, numbers_of_columns - column):
            return numbers_of_rows - row, numbers_of_columns - column

        elif self.__game_board.is_move_on_board(row, numbers_of_columns - column - 1):
            return row, numbers_of_columns - column

        elif self.__game_board.is_move_on_board(numbers_of_rows - row - 1, numbers_of_columns - column - 1):
            return numbers_of_rows - row, column

    def update_the_board_for_computer(self):
        self.__computer_player.set_game_board(self.__game_board)

    def first_move_is_computer(self):
        self.update_the_board_for_computer()
        self.__computer_player.do_first_move()

    def move_computer(self):
        self.update_the_board_for_computer()
        if self.__computer_player.computer_strategy_mirror_human() is True:
            row, column = self.get_mirror()
            self.__game_board.make_move_on_board(row+1, column+1, 'X')
        else:
            row, column = self.__computer_player.computer_moves_randomly()
            self.__game_board.make_move_on_board(row, column, 'X')
    def is_game_won(self):
        return self.__game_board.is_board_full()
