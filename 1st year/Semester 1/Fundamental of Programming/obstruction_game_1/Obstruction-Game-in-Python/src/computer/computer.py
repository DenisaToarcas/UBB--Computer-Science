class Computer:

    def computer_move(self, game):
        """
        function that executes the computer's move
        :param game: the current values on the board
        :return: - ...
        """
        maxi = -1
        poz_i = 0
        poz_j = 0
        for i in range(1, 7):
            for j in range(1, 7):
                if game[i][j] == 0:
                    nr = 0
                    if game[i-1][j-1] == 0 and i-1 != 0 and j-1 != 0:
                        nr += 1
                    if game[i-1][j] == 0 and i-1 != 0:
                        nr += 1
                    if game[i-1][j+1] == 0 and i-1 != 0 and j+1 != 7:
                        nr += 1
                    if game[i][j-1] == 0 and j-1 != 0:
                        nr += 1
                    if game[i][j+1] == 0 and j+1 != 7:
                        nr += 1
                    if game[i+1][j-1] == 0 and i+1 != 7 and j-1 != 0:
                        nr += 1
                    if game[i+1][j] == 0 and i+1 != 7:
                        nr += 1
                    if game[i+1][j+1] == 0 and i+1 != 7 and j+1 != 7:
                        nr += 1
                    if nr > maxi:
                        maxi = nr
                        poz_i = i
                        poz_j = j
        i = poz_i
        j = poz_j
        game[i][j] = 'O'
        game[i - 1][j - 1] = 1
        game[i - 1][j] = 1
        game[i - 1][j + 1] = 1
        game[i][j - 1] = 1
        game[i][j + 1] = 1
        game[i + 1][j - 1] = 1
        game[i + 1][j] = 1
        game[i + 1][j + 1] = 1
