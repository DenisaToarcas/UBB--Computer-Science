from texttable import Texttable

"""
                OBSTRUCTION
        Description:
    The game is played on a grid; 6 x 6 is a good size. One player is 'O' and the other is 'X'.

    The players take turns in writing their symbol in an empty cell. 
    Placing a symbol blocks all of the neighbouring cells from both players.
    The first player unable to move loses.
    
    0 - in our game_board means no move done there
    1 - in our game_board means human move
   -1 - in our game_board means computer move
   X - computer move
   O - human move

        *Area not available for moves will be:
             ->False when we can make moves in that square
             ->True when we can not make moves there (even for the occupied spaces for O and X)
"""


class Board:
    def __init__(self, number_of_rows: int, number_of_columns: int):
        self.__rows = number_of_rows
        self.__columns = number_of_columns
        self.__game_board = [[0 for i in range(self.__columns)] for j in range(self.__rows)]
        self.__area_not_available_for_moves = [[False for i in range(self.__columns + 1)] for j in range(self.__rows + 1)]

    def get_rows(self):
        return self.__rows
    def get_columns(self):
        return self.__columns

    def is_board_full(self):
        for row in range(self.__rows):
            for column in range(self.__columns):
                if self.__area_not_available_for_moves[row][column] is False:
                    return False
        return True

    def is_move_on_board(self, row: int, column: int) -> bool:
        if row < 0 or row > self.__rows:
            return False
        if column < 0 or row > self.__columns:
            return False
        return True

    def is_square_occupied(self, row: int, column: int):
        return self.__area_not_available_for_moves[row][column]

    def make_move_on_board(self, row: int, column: int, symbol: str):

        """if self.is_board_full() is True:
            raise TypeError('Board is already full!')"""

        if symbol not in ['X', 'O']:
            raise TypeError("Invalid symbol!")

        if self.is_move_on_board(row-1, column-1) is True and self.is_square_occupied(row-1, column-1) is False:
            if self.__area_not_available_for_moves[row-1][column-1] is False:
                if symbol == 'X':
                    self.__game_board[row-1][column-1] = -1
                elif symbol == 'O':
                    self.__game_board[row-1][column-1] = 1
                self.__area_not_available_for_moves[row-1][column-1] = True
                for surrounding_row in [-1, 0, 1]:
                    for surrounding_column in [-1, 0, 1]:
                        if self.is_move_on_board(row-1 + surrounding_row, column-1 + surrounding_column) is True:
                            row_blocked = row-1 + surrounding_row
                            column_blocked = column-1 + surrounding_column
                            self.__area_not_available_for_moves[row_blocked][column_blocked] = True
                """print(self.__game_board)
                print(self.__area_not_available_for_moves)"""
            else:
                raise Exception("We cannot overwrite a square!")

        else:
            raise Exception("Invalid move!" )



    def __str__(self):
        board = Texttable()

        header = [' ']
        for column in range(self.__columns):
            header.append(chr(ord('A') + column))

        board.header(header)

        for row in range(self.__rows):
            row_in_board = []
            for column in range(self.__columns):
                if self.__game_board[row][column] == 1:
                    row_in_board.append('O')
                    continue
                if self.__game_board[row][column] == -1:
                    row_in_board.append('X')
                    continue
                if self.__area_not_available_for_moves[row][column] is True:
                    row_in_board.append('#')
                    continue
                if self.__game_board[row][column] == 0:
                    row_in_board.append(' ')

            board.add_row([row + 1] + row_in_board)

        return board.draw()

"""
board = Board(6, 6)
board.make_move_on_board(1, 1, 'X')
board.make_move_on_board(1, 1, 'O')
board.make_move_on_board(2, 3, 'O')
print(board)
"""
