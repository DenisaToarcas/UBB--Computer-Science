from game import Game
from game import ComputerPlayer
from board import Board


class UI:
    def __init__(self, game: Game):
        self.__game = game

    def menu_for_player_move(self):
        row = 0
        column = 0

        print(self.__game.display_board())

        print("Where to move:")
        square = input(">>>")
        square_for_move = square.split()
        row = int(square_for_move[0])
        letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                                                                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                   'K']
        if square_for_move[1] in letters:
            if square_for_move[1] == 'a' or square_for_move[1] == 'A':
                column = 1
            elif square_for_move[1] == 'b' or square_for_move[1] == 'B':
                column = 2
            elif square_for_move[1] == 'c' or square_for_move[1] == 'C':
                column = 3
            elif square_for_move[1] == 'd' or square_for_move[1] == 'D':
                column = 4
            elif square_for_move[1] == 'e' or square_for_move[1] == 'E':
                column = 5
            elif square_for_move[1] == 'f' or square_for_move[1] == 'F':
                column = 6
            elif square_for_move[1] == 'g' or square_for_move[1] == 'G':
                column = 7
            elif square_for_move[1] == 'h' or square_for_move[1] == 'H':
                column = 8
            elif square_for_move[1] == 'i' or square_for_move[1] == 'I':
                column = 9
            elif square_for_move[1] == 'j' or square_for_move[1] == 'J':
                column = 10
            elif square_for_move[1] == 'k' or square_for_move[1] == 'K':
                column = 11
        else:
            raise Exception("Move out of board!")

        self.__game.move_human(row, column)

    def menu(self):
        done = False
        moves_done = []

        while done is False:
            print("\nWelcome to OBSTRUCTION!\n")
            print("     Description:\n The game is played on a grid. One player is 'O' and the other is 'X'.\n "
                  "The players take turns in writing their symbol in an empty cell.\n "
                  "Placing a symbol blocks all of the neighbouring cells from both players.\n "
                  "The first player unable to move loses.\n")

            try:
                print("Choose the dimension of the board:")
                print(" 0. 5 x 5\n 1. 6 x 5\n 2. 6 x 6\n 3. 7 x 6\n 4. 7 x 7\n 5. 8 x 7\n 6. 8 x 8\n 7. 9 x 9\n 8. 11 x 11")
                dimension = input("Write down your option here:")
                print()
                player = input("Choose who is the first one to play its move:\n 1.YOU\n 2.COMPUTER\n >>>")
                print()

                board_5X5 = "0"
                board_6X5 = "1"
                board_6X6 = "2"
                board_7X6 = "3"
                board_7X7 = "4"
                board_8X7 = "5"
                board_8X8 = "6"
                board_9X9 = "7"
                board_11X11 = "8"

                human_player = "1"
                computer_player = "2"

                if dimension == board_5X5:
                    self.__game.create_board(5, 5)
                elif dimension == board_6X5:
                    self.__game.create_board(6, 5)
                elif dimension == board_6X6:
                    self.__game.create_board(6, 6)
                elif dimension == board_7X6:
                    self.__game.create_board(7, 6)
                elif dimension == board_7X7:
                    self.__game.create_board(7, 7)
                elif dimension == board_8X7:
                    self.__game.create_board(8, 7)
                elif dimension == board_8X8:
                    self.__game.create_board(8, 8)
                elif dimension == board_9X9:
                    self.__game.create_board(9, 9)
                elif dimension == board_11X11:
                    self.__game.create_board(11, 11)
                else:
                    print("Invalid input for board!")

                if player == human_player:
                    while done is False:
                        try:
                            self.menu_for_player_move()
                            moves_done.append("human")
                            done = True
                        except Exception as exception:
                            print(exception)

                elif player == computer_player:
                    self.__game.first_move_is_computer()
                    print(self.__game.display_board())
                    moves_done.append("computer")
                    done = True

                else:
                    print("Invalid input for player!")

            except Exception as exception:
                print(exception)

        while self.__game.is_game_won() is False:
            if moves_done[len(moves_done) - 1] == "computer":
                done = False
                while done is False:
                    try:
                        self.menu_for_player_move()
                        moves_done.append("human")
                        done = True
                    except Exception as exception:
                        print(exception)

            elif moves_done[len(moves_done) - 1] == "human":
                self.__game.move_computer()
                moves_done.append("computer")
                print(self.__game.display_board())

        if self.__game.is_game_won() is True:
            print("Winner of the game is: " + moves_done.pop())
            print("Do you want to restart the game? \n 1. YES\n 2. NO")
            choice = input(">>>")

            BEGIN_AGAIN = "1"
            END_GAME = "2"

            if choice == BEGIN_AGAIN:
                self.menu()
            elif choice == END_GAME:
                print("GOODBYE :)))")
            else:
                print("Invalid choice...GOODBYE")


board = Board(0, 0)
computer_player = ComputerPlayer(board)
game = Game(board, computer_player)
ui = UI(game)
ui.menu()
