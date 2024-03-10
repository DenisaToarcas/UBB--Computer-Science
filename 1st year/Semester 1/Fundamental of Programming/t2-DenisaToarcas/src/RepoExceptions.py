class RepoException(Exception):
    def __init__(self, messages):
        self.__messages = messages

    def __repr__(self):
        return str(self)

    def __str__(self):
        return self.__messages