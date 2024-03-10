from src.board.board import Board
from src.computer.computer import Computer
from src.human.human import Human
from src.valid.valid import Valid


class Ui:

    def __init__(self, board, computer, human, valid):
        self.__board = board
        self.__computer = computer
        self.__human = human
        self.__valid = valid

    def print_board(self, game):
        print('\t _____ _____ _____ _____ _____ _____')
        for i in range(1, 7):
            s = '\t| '
            for j in range(1, 7):
                if game[i][j] == 1:
                    s += '\033[2;30;47m   \033[0;0m'
                elif game[i][j] == 0:
                    s += '   '
                elif game[i][j] == 'X':
                    s += ' X '
                elif game[i][j] == 'O':
                    s += ' O '
                s += ' | '
            print(s)
            print('\t|_____|_____|_____|_____|_____|_____|')
        print("\n")

    def human_first(self, game):
        while True:
            print("Human's turn!")
            ok = 0
            while ok == 0:
                i = input("Row: ")
                try:
                    self.__valid.validate_row(i)
                    i = int(i)
                    ok = 1
                except Exception as ex:
                    print(ex)
            ok = 0
            while ok == 0:
                j = input("Column: ")
                try:
                    self.__valid.validate_column(j)
                    j = int(j)
                    ok = 1
                except Exception as ex:
                    print(ex)
            try:
                self.__valid.validate_move(game, i, j)
                self.__human.human_move(game, i, j)
                self.print_board(game)
                if self.__board.check_board(game) == False:
                    print("Human wins!")
                    return
                print("Computer's turn!")
                self.__computer.computer_move(game)
                self.print_board(game)
                if self.__board.check_board(game) == False:
                    print("Computer wins!")
                    return
            except Exception as ex:
                print(ex)
                print("")
                print("")

    def computer_first(self, game):
        ok = 1
        while True:
            if ok == 1:
                print("Computer's turn!")
                self.__computer.computer_move(game)
                self.print_board(game)
                if self.__board.check_board(game) == False:
                    print("Computer wins!")
                    return
            print("Human's turn!")
            ok = 0
            while ok == 0:
                i = input("Row: ")
                try:
                    self.__valid.validate_row(i)
                    i = int(i)
                    ok = 1
                except Exception as ex:
                    print(ex)
            ok = 0
            while ok == 0:
                j = input("Column: ")
                try:
                    self.__valid.validate_column(j)
                    j = int(j)
                    ok = 1
                except Exception as ex:
                    print(ex)
            try:
                self.__valid.validate_move(game, i, j)
                ok = 1
                self.__human.human_move(game, i, j)
                self.print_board(game)
                if self.__board.check_board(game) == False:
                    print("Human wins!")
                    return
            except Exception as ex:
                print(ex)
                print("")
                print("")
                ok = 0

    def start(self):
        game = []
        for i in range(0, 8):
            game.append([0, 0, 0, 0, 0, 0, 0, 0])
        print("")
        print("OBSTRUCTION")
        print("   X -> human")
        print("   O -> computer")
        self.print_board(game)
        ok = 0
        while ok == 0:
            turn = input("Turn(human or computer): ")
            if turn == 'human' or turn == 'computer':
                ok = 1
            else:
                print("Invalid choice!")
        print("")
        print("")
        if turn == 'human':
            self.human_first(game)
        else:
            self.computer_first(game)


board = Board()
computer = Computer()
human = Human()
valid = Valid()
ui = Ui(board, computer, human, valid)
ui.start()
