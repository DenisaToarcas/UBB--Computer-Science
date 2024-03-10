class Human:

    def human_move(self, game, i, j):
        """
        function that executes the human's move
        :param game: the current values on the board
        :param i: row index
        :param j: column index
        :return: - ...
        """
        game[i][j] = 'X'
        game[i-1][j-1] = 1
        game[i-1][j] = 1
        game[i-1][j+1] = 1
        game[i][j-1] = 1
        game[i][j+1] = 1
        game[i+1][j-1] = 1
        game[i+1][j] = 1
        game[i+1][j+1] = 1
