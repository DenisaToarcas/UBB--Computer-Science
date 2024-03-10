import unittest
from src.board.board import Board
from src.computer.computer import Computer
from src.human.human import Human
from src.valid.valid import Valid


class Test(unittest.TestCase):

    def setUp(self) -> None:
        self.board = Board()
        self.computer = Computer()
        self.human = Human()
        self.valid = Valid()

    def test_check_board(self):
        ok=1
        game = [[1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 0, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]]
        self.assertEqual(self.board.check_board(game), True)
        game = [[1, 1, 1, 1, 1, 1, 1, 1],
                [0, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 0]]
        self.assertEqual(self.board.check_board(game), False)

    def test_computer_move(self):
        game = [[1, 1, 1, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]]
        self.computer.computer_move(game)
        game_after = [[1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 0, 0, 1, 1, 1, 1, 1],
                      [1, 0, 0, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 'O', 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1]]
        self.assertEqual(game, game_after)

    def test_human_move(self):
        game = [[1, 1, 1, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]]
        i = 4
        j = 4
        self.human.human_move(game, i, j)
        game_after = [[1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 0, 0, 1, 1, 1, 1, 1],
                      [1, 0, 0, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 'X', 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1],
                      [1, 1, 1, 1, 1, 1, 1, 1]]
        self.assertEqual(game, game_after)

    def test_validate_row(self):
        i = '3'
        self.valid.validate_row(i)
        i = 'abc'
        try:
            self.valid.validate_row(i)
        except Exception as ex:
            self.assertEqual(str(ex), "Row should be an integer!")
        i = '9'
        try:
            self.valid.validate_row(i)
        except Exception as ex:
            self.assertEqual(str(ex), "Row should be between 1 and 6!")

    def test_validate_column(self):
        j = '3'
        self.valid.validate_column(j)
        j = 'abc'
        try:
            self.valid.validate_column(j)
        except Exception as ex:
            self.assertEqual(str(ex), "Column should be an integer!")
        j = '9'
        try:
            self.valid.validate_column(j)
        except Exception as ex:
            self.assertEqual(str(ex), "Column should be between 1 and 6!")

    def test_validate_move(self):
        game = [[1, 1, 1, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 0, 0, 1, 1, 1, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 0, 0, 0, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]]
        i = 2
        j = 2
        self.valid.validate_move(game, i, j)
        i = 1
        j = 3
        try:
            self.valid.validate_move(game, i, j)
        except Exception as ex:
            self.assertEqual(str(ex), "Move is not available!")


if __name__ == "__main__":
    unittest.main()
