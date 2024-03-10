from board import Board
import random
from random import choice

class ComputerPlayer:
    def __init__(self, game_board: Board):
        self.__game_board = game_board
        self.__moves = []

    def get_game_board(self):
        return self.__game_board

    def set_game_board(self, game_board_updated):
        self.__game_board = game_board_updated

    def check_parity_of_game_board(self):
        """
        :return: True only when the board created has an odd number of rows and columns
        """

        number_of_rows = self.__game_board.get_rows()
        number_of_columns = self.__game_board.get_columns()
        #print(number_of_rows)
        #print(number_of_columns)

        if number_of_rows % 2 == 1 and number_of_columns % 2 == 1:
            return True
        else:
            return False

    def do_first_move(self):
        """
        If the board is odd and AI makes the first move, then the first move will be in the center of the board.
        In order to win, next the AI will only mirror the player's moves."""
        if self.check_parity_of_game_board() is True:
            self.__game_board.make_move_on_board(self.__game_board.get_rows() // 2 + 1,
                                                 self.__game_board.get_columns() // 2 + 1, 'X')
            self.__moves.append("first")
        else:
            [row, column] = self.computer_moves_randomly()
            self.__game_board.make_move_on_board(row, column, 'X')

    def computer_strategy_mirror_human(self):
        if self.check_parity_of_game_board() is True and len(self.__moves) != 0:
            return True
        return False

    def computer_moves_randomly(self):
        """On even by even or even by odd sized boards there is no known winning strategy,
        and it makes for a challenging game."""

        row = random.choice(range(0, self.__game_board.get_rows()))
        column = random.choice(range(0, self.__game_board.get_columns()))
        while self.__game_board.is_square_occupied(row, column) is True:
            row = random.choice(range(0, self.__game_board.get_rows()))
            column = random.choice(range(0, self.__game_board.get_columns()))

        return row+1, column+1



