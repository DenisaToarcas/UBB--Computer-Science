from board import Board
from game import Game
from ui import UI

board = Board()
game = Game(board)
ui = UI(game)

ui.menu()