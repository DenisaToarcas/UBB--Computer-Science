"""
    Add a new student to the list of students.
    Each student must have:
    -> an id, which is an integer
    -> a name, which is a string
    -> a group, which is a positive integer
    """
class student:
    def __int__(self, id:int, name:str, group:int):
        self.__id = id
        self.__name = name
        self.__group = group

    @property
    def student_id(self):
        return self.__id

    @student_id.setter
    def student_id(self, new_id: int):
        self.__id = new_id

    @property
    def student_name(self):
        return self.__name

    @student_name.setter
    def student_name(self, given_name: str):
        self.__name = given_name

    @property
    def student_group(self):
        return self.__group

    @student_group.setter
    def student_group(self, given_group : int):
        self.__group = given_group

    def __repr__(self):
        return str(self)

    @property
    def __str__(self):
        return self.id + "-> " + "Name: " + self.name + ", group: " + self.group


def test_students() -> object:
    test_student = student(1234, "Pop Ioana", 917)
    assert test_student.id == 1234
    assert test_student.name == "Pop Ioana"
    assert test_student.group == 917
    assert str(test_student) == "1234-> Name: Pop Ioana, group: 917"

    test_student.id = 1222
    assert test_student.id == 1222

    test_student.group = 911
    assert test_student.group == 911

if __name__ == "__main__":
    test_students()
