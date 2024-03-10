from texttable import Texttable


class Board:
    def __init__(self):
        self.__rows = 3
        self.__columns = 3
        self.__game_board = [[0 for i in range(0, 3)] for j in range(0, 3)]
        self.__occupied_squares = [[False for i in range(0, 3)] for j in range(0, 3)]

    def get_rows(self):
        return self.__rows

    def get_columns(self):
        return self.__columns

    def get_symbol(self, row, column):
        """:param: row, column - indicate the square of which symbol we want to get
        It returns the actual symbol that it finds on the board
        - if the value found on the board is 1 => returns symbol 'O'
        - if the value found on the board is -1 => returns symbol 'X'
        - else, returns ' ' (empty space, cause the square is not occupied)
        """
        if self.__game_board[row][column] == 1:
            return 'O'
        elif self.__game_board[row][column] == -1:
            return 'X'
        else:
            return ' '

    def is_move_on_board(self, row: int, column: int) -> bool:
        if row < 0 or row > self.__rows:
            return False
        if column < 0 or row > self.__columns:
            return False
        return True

    def make_move_on_board(self, row, column, symbol):
        if self.is_move_on_board(row, column) is True and self.__occupied_squares[row][column] is False:
            if symbol == 'O':
                self.__game_board[row][column] = 1
                self.__occupied_squares[row][column] = True
            elif symbol == 'X':
                self.__game_board[row][column] = -1
                self.__occupied_squares[row][column] = True
        else:
            raise ValueError("Invalid move!")

    def is_square_occupied(self, row, column):
        return self.__occupied_squares[row][column]

    def is_there_any_wins(self):
        for i in range(0, 3):
            if self.get_symbol(i, 0) == self.get_symbol(i, 1) == self.get_symbol(i, 2):
                return self.get_symbol(i, 0)

        for j in range(0, 3):
            if self.get_symbol(0, j) == self.get_symbol(1, j) == self.get_symbol(2, j):
                return self.get_symbol(0, j)

        if self.get_symbol(0, 0) == self.get_symbol(1, 1) == self.get_symbol(2, 2):
            return self.get_symbol(0, 0)

        if self.get_symbol(0, 2) == self.get_symbol(1, 1) == self.get_symbol(2, 0):
            return self.get_symbol(1, 1)

        else:
            return ' '

    def is_square_adjacent(self, row_from_where: int, column_from_where: int, new_row: int, new_column: int):
        """:param: row_from_where, column_from_where, new_row, new_column - these, 2 by 2, form the squares we want to verify if they are adjacent or not
        It returns True if the squares are adjacent or False, otherwise"""
        if new_row == row_from_where or new_row == row_from_where + 1 or new_row == row_from_where - 1:
            if new_column == column_from_where or new_column == column_from_where + 1 or new_column == column_from_where - 1:
                return True
        return False

    def move_elements_on_board(self, row_from_where: int, column_from_where: int, new_row: int, new_column: int,
                               symbol):
        if self.is_move_on_board(row_from_where, column_from_where) is True and self.is_move_on_board(new_row,
                                                                                                      new_column) is True and self.is_square_adjacent(
                row_from_where, column_from_where, new_row, new_column) is True:
            if self.get_symbol(row_from_where, column_from_where) == symbol:
                if self.__occupied_squares[new_row][new_column] is False:
                    self.__game_board[row_from_where][column_from_where] = 0
                    self.__occupied_squares[row_from_where][column_from_where] = False
                    self.__occupied_squares[new_row][new_column] = True
                    if symbol == 'X':
                        self.__game_board[new_row][new_column] = -1
                    else:
                        self.__game_board[new_row][new_column] = 1
        else:
            raise Exception("Cannot move here!")

    def __str__(self):
        board = Texttable()

        for row in range(self.__rows):
            row_in_board = []
            for column in range(self.__columns):
                if self.__game_board[row][column] == 1:
                    row_in_board.append('O')
                    continue
                if self.__game_board[row][column] == -1:
                    row_in_board.append('X')
                    continue
                if self.__game_board[row][column] == 0:
                    row_in_board.append(' ')

            board.add_row(row_in_board)

        return board.draw()
