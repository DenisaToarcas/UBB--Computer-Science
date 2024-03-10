class validation_errors:
    def __init__(self, list_of_errors):
        self.__list_of_errors = list_of_errors

    def __repr__(self):
        return str(self.__list_of_errors)

    def __str__(self):
        list_of_messages = ""
        for message in self.__list_of_errors:
            list_of_messages += message
            list_of_messages += "\n"
        return list_of_messages