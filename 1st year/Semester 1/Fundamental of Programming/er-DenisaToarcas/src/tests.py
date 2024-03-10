from board import Board
import unittest

class Tests(unittest.TestCase):
    game_board_tests = Board()

    def test_get_symbol(self):
        self.game_board_tests.make_move_on_board(1, 1, 'X')
        self.assertEqual(self.game_board_tests.get_symbol(1, 1), 'X')

        self.game_board_tests.make_move_on_board(2, 2, 'O')
        self.assertEqual(self.game_board_tests.get_symbol(2, 2), 'O')

    def test_is_square_adjacent(self):
        self.assertEqual(self.game_board_tests.is_square_adjacent(1, 1, 0, 1), True)
        self.assertEqual(self.game_board_tests.is_square_adjacent(1, 0, 1, 2), False)
        self.assertEqual(self.game_board_tests.is_square_adjacent(2, 1, 2, 2), True)
        self.assertEqual(self.game_board_tests.is_square_adjacent(0, 0, 2, 2), False)