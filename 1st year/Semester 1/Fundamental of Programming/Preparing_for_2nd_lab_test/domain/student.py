class Student:
    def __init__(self, id: int, name: str, playing_strength: int):
        self.__id = id
        self.__name = name
        self.__playing_strength = playing_strength

    @property
    def id(self):
        return self.__id
    @id.setter
    def id(self, new_id: int):
        self.__id = new_id

    @property
    def name(self):
        return self.__name
    @name.setter
    def name(self, new_name: str):
        self.__name = new_name

    @property
    def playing_strength(self):
        return self.__playing_strength
    @playing_strength.setter
    def playing_strength(self, new_playing_strength: int):
        self.__playing_strength = new_playing_strength

    def __str__(self):
        return str(self.__id) + " " + str(self.__name) + " " + str(self.__playing_strength)

    def __repr__(self):
        return str(self)

class StudentValidator:
    def validate(self, student):
        if isinstance(student, Student) is False:
            raise TypeError("We can only validate only Student type objects!")