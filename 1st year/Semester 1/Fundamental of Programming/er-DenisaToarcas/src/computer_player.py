from board import Board
import random


class ComputerPlayer:
    def __init__(self, game_board: Board):
        self.__game_board = game_board
        self.__moves = []

    def get_game_board(self):
        return self.__game_board

    def set_game_board(self, game_board_updated):
        self.__game_board = game_board_updated

    def computer_moves_randomly(self):
        row = random.choice(range(0, self.__game_board.get_rows()))
        column = random.choice(range(0, self.__game_board.get_columns()))
        while self.__game_board.is_square_occupied(row, column) is True:
            row = random.choice(range(0, self.__game_board.get_rows()))
            column = random.choice(range(0, self.__game_board.get_columns()))

        return row, column

    def where_to_make_moves_on_board(self, symbol: str):
        row_from_where = random.choice(range(0, self.__game_board.get_rows()))
        column_from_where = random.choice(range(0, self.__game_board.get_columns()))
        while self.__game_board.is_square_occupied(row_from_where, column_from_where) is True and self.__game_board.get_symbol(row_from_where, column_from_where) != symbol or self.__game_board.is_square_adjacent(row_from_where, column_from_where) is False:
            new_row = random.choice(range(0, self.__game_board.get_rows()))
            new_column = random.choice(range(0, self.__game_board.get_columns()))
            if self.__game_board.is_square_occupied(new_row, new_column) is False and self.__game_board.is_square_adjacent(row_from_where, column_from_where, new_row, new_column) is True:
                return row_from_where, column_from_where, new_row, new_column
