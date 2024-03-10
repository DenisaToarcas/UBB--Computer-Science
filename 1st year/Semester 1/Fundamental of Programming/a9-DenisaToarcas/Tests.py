import unittest
from board import Board

class BoardTests(unittest.TestCase):

    def test_get_rows(self):
        board = Board(5, 5)
        self.assertEqual(board.get_rows(), 5)
        board = Board(7, 7)
        self.assertEqual(board.get_rows(), 7)

    def test_get_columns(self):
        board = Board(5, 5)
        self.assertEqual(board.get_columns(), 5)
        board = Board(7, 7)
        self.assertEqual(board.get_columns(), 7)

    def test_is_board_full(self):
        board = Board(5, 5)
        self.assertEqual(board.is_board_full(), False)
        board.make_move_on_board(2, 2, 'X')
        self.assertEqual(board.is_board_full(), False)

    def test_is_move_on_board(self):
        board = Board(7, 6)
        self.assertEqual(board.is_move_on_board(2, 3), True)
        self.assertEqual(board.is_move_on_board(8, 4), False)

    def test_is_square_occupied(self):
        board = Board(9, 9)
        board.make_move_on_board(2, 4, 'X')
        self.assertEqual(board.is_square_occupied(1, 3), True)
        self.assertEqual(board.is_square_occupied(8, 8), False)

    def test_make_move_on_board(self):
        board = Board(9, 9)
        try:
            board.make_move_on_board(2, 4, 'X')
            self.assertEqual(board.is_square_occupied(1, 3), True)
            board.make_move_on_board(2, 4, 'O')
        except Exception as exception:
            print(exception)

    def test_make_move_on_board1(self):
        board = Board(9, 9)
        try:
            board.make_move_on_board(2, 4, 'A')
        except Exception as exception:
            print(exception)
