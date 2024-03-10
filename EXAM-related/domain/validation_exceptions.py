class ValidationException(Exception):
    def __init__(self, messages):
        self.messages = messages

    def get_message(self):
        return self.messages

    def __repr__(self):
        return str(self)

    def __str__(self):
        list_of_exceptions = ""
        for error in self.messages:
            list_of_exceptions += error
            list_of_exceptions += "\n"

        return list_of_exceptions
