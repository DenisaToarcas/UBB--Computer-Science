class Board:

    def check_board(self, game):
        """
        function that checks if there are any possible moves left
        :param game: the current values on the board
        :return: True or False ...
        """
        for i in range(1, 7):
            for j in range(1, 7):
                if game[i][j] == 0:
                    return True
        return False
