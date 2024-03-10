class Valid:

    def validate_row(self, i):
        """
        function that validates the row index
        :param i: the row
        :return: - ...
        """
        if i.isnumeric() == False:
            raise Exception("Row should be an integer!")
        i = int(i)
        if i < 1 or i > 6:
            raise Exception("Row should be between 1 and 6!")

    def validate_column(self, j):
        """
        function that validates the column index
        :param j: the column
        :return: -
        """
        if j.isnumeric() == False:
            raise Exception("Column should be an integer!")
        j = int(j)
        if j < 1 or j > 6:
            raise Exception("Column should be between 1 and 6!")

    def validate_move(self, game, i, j):
        """
        function that validates the move
        :param game: the current values on the board
        :param i: the row
        :param j: the column
        :return: -
        """
        if game[i][j] != 0:
            raise Exception("Move is not available, try again!")
