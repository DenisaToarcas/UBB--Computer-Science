from computer_player import ComputerPlayer
from board import Board

class Game:
    def __init__(self, game_board: Board, computer_player: ComputerPlayer):
        self.__game_board = game_board
        self.__computer_player = computer_player
        self.__placement_human = []

    def create_board(self):
        self.__game_board = Board()

    def display_board(self):
        return str(self.__game_board)

    def is_move_on_board(self, row: int, column: int):
        return self.__game_board.is_move_on_board(row, column)

    def move_human(self, row: int, column: int, symbol: str):
        self.__game_board.make_move_on_board(row, column, symbol)
        self.__placement_human.append([row, column])
        self.update_the_board_for_computer()

    def move_computer(self, row: int, column: int, symbol: str):
        self.__game_board.make_move_on_board(row, column, symbol)
        self.update_the_board_for_computer()

    def get_moves_of_computer(self):
        row, column = self.__computer_player.computer_moves_randomly()
        return row, column

    def update_the_board_for_computer(self):
        self.__computer_player.set_game_board(self.__game_board)

    def move_elements_on_board(self, row_from_where: int, column_from_where: int, new_row: int, new_column: int, symbol):
        self.__game_board.move_elements_on_board(row_from_where, column_from_where, new_row, new_column, symbol)

    def get_movements_of_computer(self, symbol_given: str):
        row_from_where, column_from_where, new_row, new_column = self.__computer_player.where_to_make_moves_on_board(symbol_given)
        self.move_elements_on_board(row_from_where, column_from_where, new_row, new_column, symbol_given)

    def is_game_won(self):
        winner = self.__game_board.is_there_any_wins()
        if winner != ' ':
            return winner
        else:
            return False