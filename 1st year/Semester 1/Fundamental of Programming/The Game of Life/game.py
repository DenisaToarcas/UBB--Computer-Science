from board import Board
from texttable import Texttable


class Game:
    def __init__(self, game_board: Board, file_name="cell_patterns.txt"):
        self.__game_board = game_board
        self.__file_name = file_name
        self.store_patterns_in_text_file()

    def display_game_board(self):
        return self.__game_board

    def place_on_board(self, pattern: str, coordinates: str):
        x, y = coordinates.split(',')

        if x < '0' or x > '9' or y < '0' or y > '9':
            raise TypeError("Invalid coordinates given!!!")

        row = int(x)
        col = int(y)

        """raise ValueError("Out of board move cell!!!")
        raise Exception("We cannot overlap other lives cells!!!")"""

        if self.__game_board.is_move_on_board(row, col) is True:
            if pattern == "block":
                self.place_block_on_board(row, col)

            elif pattern == "tub":
                self.place_tub_on_board(row, col)

            elif pattern == "blinker":
                self.place_blinker_on_board(row, col)

            elif pattern == "beacon":
                self.place_beacon_on_board(row, col)

            else:
                raise ValueError("Invalid pattern!!!")
        else:
            raise Exception("We cannot place this pattern on board!!!")

    def place_block_on_board(self, row, col):
        if self.__game_board.is_move_on_board(row, col + 1) is True and self.__game_board.is_move_on_board(row + 1, col) is True and self.__game_board.is_move_on_board(row + 1, col + 1) is True:
            self.__game_board.place_x(row, col)
            self.__game_board.place_x(row + 1, col)
            self.__game_board.place_x(row, col + 1)
            self.__game_board.place_x(row + 1, col + 1)
        else:
            raise Exception("We cannot place this pattern on board!!!")

    def place_tub_on_board(self, row, col):
        if self.__game_board.is_move_on_board(row + 1, col - 1) is True and self.__game_board.is_move_on_board(row + 1,col + 1) is True and self.__game_board.is_move_on_board(row + 2, col) is True:
            self.__game_board.place_x(row, col)
            self.__game_board.place_x(row + 1, col - 1)
            self.__game_board.place_x(row + 1, col + 1)
            self.__game_board.place_x(row + 2, col)
        else:
            raise Exception("We cannot place this pattern on board!!!")

    def place_blinker_on_board(self, row, col):
        if self.__game_board.is_move_on_board(row, col + 1) is True and self.__game_board.is_move_on_board(row, col + 2) is True:
            self.__game_board.place_x(row, col)
            self.__game_board.place_x(row, col + 1)
            self.__game_board.place_x(row, col + 2)

        elif self.__game_board.is_move_on_board(row + 1, col) is True and self.__game_board.is_move_on_board(row + 2, col) is True:
            self.__game_board.place_x(row, col)
            self.__game_board.place_x(row + 1, col)
            self.__game_board.place_x(row + 2, col)
        else:
            raise Exception("We cannot place this pattern on board!!!")

    def place_beacon_on_board(self, row, col):
        if self.__game_board.is_move_on_board(row, col + 1) is True and self.__game_board.is_move_on_board(row + 1, col) and self.__game_board.is_move_on_board(row + 2, col + 3) is True and self.__game_board.is_move_on_board(row + 3, col + 2) is True and self.__game_board.is_move_on_board(row + 3, col + 3):
            self.__game_board.place_x(row, col)
            self.__game_board.place_x(row, col + 1)
            self.__game_board.place_x(row + 1, col)
            self.__game_board.place_x(row + 2, col + 3)
            self.__game_board.place_x(row + 3, col + 2)
            self.__game_board.place_x(row + 3, col + 3)
        else:
            raise Exception("We cannot place this pattern on board!!!")

        if self.__game_board.is_move_on_board(row + 1, col + 1) is True and self.__game_board.is_move_on_board(row + 2, col + 2) is True:
            self.__game_board.place_x(row + 1, col + 1)
            self.__game_board.place_x(row + 2, col + 2)

    def store_patterns_in_text_file(self):
        block = Texttable()

        for row in range(0, 2):
            row_in_block = []
            for col in range(0, 2):
                row_in_block.append('X')

            block.add_row(row_in_block)

        block_str = block.draw()

        tub = Texttable()

        for row in range(0, 3):
            row_in_block = []
            for col in range(0, 3):
                if row == 0 and col == 1:
                    row_in_block.append('X')
                elif row == 1 and col == 0:
                    row_in_block.append('X')
                elif row == 1 and col == 2:
                    row_in_block.append('X')
                elif row == 2 and col == 1:
                    row_in_block.append('X')
                else:
                    row_in_block.append(' ')

            tub.add_row(row_in_block)

        tub_str = tub.draw()

        blinker = Texttable()

        for row in range(0, 3):
            row_in_block = []
            for col in range(0, 3):
                if row == 1:
                    row_in_block.append('X')
                else:
                    row_in_block.append(' ')

            blinker.add_row(row_in_block)

        blinker_str = blinker.draw()

        blinker_1 = Texttable()

        for row in range(0, 3):
            row_in_block = []
            for col in range(0, 3):
                if col == 1:
                    row_in_block.append('X')
                else:
                    row_in_block.append(' ')

            blinker_1.add_row(row_in_block)

        blinker_1_str = blinker_1.draw()

        file_output = open(self.__file_name, 'w')

        file_output.write("block:\n")
        file_output.write(block_str)
        file_output.write("\n")

        file_output.write("tub:\n")
        file_output.write(tub_str)
        file_output.write("\n")

        file_output.write("blinker:\n")
        file_output.write(blinker_str)
        file_output.write("\n")

        file_output.write("blinker: alternate\n")
        file_output.write(blinker_1_str)
        file_output.write("\n")

        file_output.close()

    def save_state(self, file_name: str):
        output_file = open(file_name, 'w')

        output_file.write(str(self.display_game_board()))

        output_file.close()



