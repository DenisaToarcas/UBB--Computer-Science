"""
class RepoExceptions(Exception):
    def __init__(self, list_of_exceptions):
        self.__list_of_exceptions = list_of_exceptions

    def get_all_errors(self):
        return self.__list_of_exceptions

    def __repr__(self):
        return str(self)

    def __str__(self):
        list_of_exceptions = ""
        for exception in self.__list_of_exceptions:
            list_of_exceptions += exception
            list_of_exceptions += "\n"

        return list_of_exceptions
"""


class RepoExceptions(Exception):
    def __init__(self, messages):
        self.__messages = messages

    @property
    def message(self):
        return self.__messages

    def __str__(self):
        return self.__messages
