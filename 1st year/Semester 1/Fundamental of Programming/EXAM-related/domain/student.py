class Student:
    def __init__(self, id: int, name: str, group: str):
        self.__id = id
        self.__name = name
        self.__group = group

    def __str__(self):
        return str(self.id) + " " + self.name + " " + self.group

    def __repr__(self):
        return str(self)

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
    def name(self, different_name: str):
        self.__name = different_name

    @property
    def group(self):
        return self.__group

    @group.setter
    def group(self, different_group: str):
        self.__group = different_group
