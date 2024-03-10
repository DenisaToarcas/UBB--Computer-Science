from texttable import Texttable


class Board:
    def __init__(self):
        self.__rows = 8
        self.__columns = 8
        self.__game_board = [[0 for i in range(self.__columns)] for j in range(self.__rows)]

    def get_rows(self):
        return self.__rows

    def get_columns(self):
        return self.__columns

    def __str__(self):
        board = Texttable()

        for row in range(self.__rows):
            row_in_board = []
            for col in range(self.__columns):
                if self.__game_board[row][col] == 0:
                    row_in_board.append(' ')
                else:
                    row_in_board.append('X')

            board.add_row(row_in_board)

        return board.draw()

    def is_move_on_board(self, row: int, col: int):
        if row < 0 or row > 7:
            return False
        if col < 0 or col > 7:
            return False
        if self.__game_board[row][col] == 1:
            return False
        return True

    def place_x(self, row: int, col: int):
        self.__game_board[row][col] = 1


"""
board = Board()
print(str(board))
"""
