import random
import pickle
from src.domain.student import student

class RepoException(Exception):
    pass


class MemoryRepository:
    def __init__(self):
        self._data = []
        self._undoList = []

    def __len__(self):
        return len(self._data)

    def get_student(self, id: int):
        return self._data[id]

    def add_student(self, new_student: student):
        if new_student.id in self._data:
            raise RepoException("Student is already in the list!")
        else:
            self._data.append(new_student)
            self._undoList.append(self._data.copy())
    #adds a student to the list of students

    """
        def get_student_id(self, student_id: int):
        try:
            return self._data[student_id]
        except KeyError:
            raise RepoException("The given id does not correspond with any of the student's id in list!")

    def get_student_group(self, student_group: int):
        try:
            if student_group in self._data:
                student = self._data
                return self._data[student.id]
        except KeyError:
            raise RepoException("No student is part of the given group!")
    """
    def get_all(self):
        return self._data[:]
    """gets the list of students and returns it"""

    def delete_students_from_group(self, group: int):
        try:
            list_of_students = self._data
            index = 0
            while index < len(self._data):
                student = self._data[index]
                if student.group == group:
                    list_of_students.remove(student)
                else:
                    index = index + 1
            self._data = list_of_students
            self._undoList.append(self._data.copy())

        except KeyError:
            raise RepoException("There is no student in the given group!")
    #deletes the students from a specific group, written on the console

    def undo(self):
        """
        This function undoes the last operation that modified the list of students
        """

        """
        try:
            self._undoList.pop()
            self._data = self._undoList[-1]
            
        except keyError:
            raise RepoException("We cannot do the undo operation anymore!!!")
            
        """
        if len(self._undoList) > 10:
            self._undoList.pop()
            self._data = self._undoList[-1]

        else:
            if len(self._undoList) == 10:
                raise RepoException("We cannot do the undo operation anymore!!!")


class TextFileRepository(MemoryRepository):
    #this class inherits from MemoryRepository
    #it has all the attributes and methods that MemoryRepository has

    def __init__(self, file_name="..\\src\\student.txt"):
        #call the superclass constructor
        super(TextFileRepository, self).__init__()
        #remember the name of the file we are working on
        self._file_name = file_name
        #load all the students from the txt file
        self._load_file()

    def _load_file(self):
        """
        Load the students from a text file
        """
        # t - text file mode, r - reading

        students = []

        try:
            file_input = open(self._file_name, "rt")
            # each student with his info should be on his own line
            students = file_input.readlines()
            # close the file when done reading
            file_input.close()
        except IOError:
            raise RepoException("Input file was not found!")

        for student_in_list in students:
            current_student = student_in_list.split()
            new_student = student(int(current_student[0]), current_student[1], int(current_student[2]))
            # NOTE call super() so that we don't write the file we're reading from
            super(TextFileRepository, self).add_student(new_student)

    def _save_file(self):
        """
        Save the students in the text file
        """
        #w - write mode, t - text file
        file_output = open(self._file_name, "wt")

        for student_in_list in self.get_all():
            student_in_str_form = str(student_in_list.id) + "-> Name: " + student_in_list.name + ", group " \
                                  + str(student_in_list.group)
            file_output.write(student_in_str_form)

        #closing the text file after we are done writing
        file_output.close()

    def add_student(self, new_student: student):
        super(TextFileRepository, self).add_student(new_student)
        self._save_file()

    """def get_student(self, id: int):
        return super(TextFileRepository, self).get_student(id)

    def get_all(self):
        return super(TextFileRepository, self).get_all()"""

    def delete_students_from_group(self, group: int):
        super(TextFileRepository, self).delete_students_from_group(group)
        self._save_file()

    def undo(self):
        super(TextFileRepository, self).undo()
        self._save_file()


class BinaryFileRepository(MemoryRepository):
    def __init__(self, file_name="student.bin"):
        super(BinaryFileRepository, self).__init__()
        self._file_name = file_name
        #load all students from the binary file
        self._load_file()

    def add_student(self, new_student: student):
        super(BinaryFileRepository, self).add_student(new_student)
        #save all the students to the binary file
        self._save_file()

    """def get_student(self, id: int):
        self._save_file()
        return super(BinaryFileRepository, self).get_student(id)

    def get_all(self):
        self._save_file()
        return super(BinaryFileRepository, self).get_all()"""

    def delete_students_from_group(self, group: int):
        super(BinaryFileRepository, self).delete_students_from_group(group)
        self._save_file()

    def undo(self):
        super(BinaryFileRepository, self).undo()
        self._save_file()

    def _load_file(self):
        # r - read, b - binary
        file_input = open(self._file_name, "rb")
        obj = pickle.load(file_input)

        for student in obj:
            super().add_student(student)
        file_input.close()

    def _save_file(self):
        # w - write mode (overwrite), b - binary mode
        file_output = open(self._file_name, "wb")
        pickle.dump(self.get_all(), file_output)
        file_output.close()


def generate_students():
    students_id = [1212, 2323, 3434, 4545, 5656, 6767, 7878, 8989, 9090, 10101]
    students_names = ["Lavinia Grecu", "Tudor Dragu", "Steluta Luminita", "Popescu Ionela", "Amandina Trambulina",
                      "Carolina Jambala", "Bogdan Ionescu", "Ana Cotoran", "Havana Lua", "Vivi Ducan"]
    students_groups = [911, 912, 913, 914, 915, 916, 917]

    student_list = []
    for i in range(0, 10):
        id = students_id[i]
        name = students_names[i]
        group = random.choice(students_groups)

        student_list.append(student(id, name, group))

    return student_list

def test_add_student():
    repository = MemoryRepository()
    assert len(repository) == 0

    student1 = student(11111, "Ana", 900)
    repository.add_student(student1)
    student2 = student(22222, "Maria", 911)
    repository.add_student(student2)
    assert len(repository) == 2

def test_delete_students_from_group():
    repository = MemoryRepository()
    repository.add_student(student(11111, "Ana", 918))
    repository.add_student(student(22222, "Mara", 911))
    repository.delete_students_from_group(911)
    assert len(repository) == 1

test_add_student()
test_delete_students_from_group()

