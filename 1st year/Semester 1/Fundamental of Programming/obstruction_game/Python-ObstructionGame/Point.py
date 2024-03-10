class Point:
    def __init__(self, x, y):
        self.__x = int(x)
        self.__y = int(y)

    def get_x(self):
        return self.__x

    def get_y(self):
        return self.__y