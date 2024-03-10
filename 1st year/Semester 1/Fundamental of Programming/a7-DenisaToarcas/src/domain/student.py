class student:

    def __init__(self, id: int, name: str, group: int):
        self.id = id
        self.name = name
        self.group = group

    """
            Add a new student to the list of students.
            Each student must have:
                -> an id, which is an integer
                -> a name, which is a string
                -> a group, which is a positive integer
    """

    @property
    def student_id(self):
        return self.id

    @student_id.setter
    def student_id(self, new_id: int):
        self.id = new_id

    @property
    def student_name(self):
        return self.name

    @student_name.setter
    def student_name(self, given_name: str):
        self.name = given_name

    @property
    def student_group(self):
        return self.group

    @student_group.setter
    def student_group(self, given_group: int):
        self.group = given_group

    def __repr__(self):
        return str(self)

    def __str__(self):
        return str(self.id)+ "-> " + "Name: " + self.name + ", group: " + str(self.group)


def test_student():
    student_created_for_test: student = student(1234, "Pop Ioana", 917)
    assert student_created_for_test.id == 1234
    assert student_created_for_test.name == "Pop Ioana"
    assert student_created_for_test.group == 917
    assert str(student_created_for_test) == "1234-> Name: Pop Ioana, group: 917"

    student_created_for_test.id = 1222
    assert student_created_for_test.id == 1222

    student_created_for_test.group = 911
    assert student_created_for_test.group == 911

test_student()

