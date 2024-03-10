import random
import pickle

class RepoException(Exception):
    pass


class MemoryRepository(object):
    def __int__(self):
        self._data = {}

    def add_student(self, new_student: student):
        if type(new_student) != student:
            raise TypeError("Can only add students to the list!")
        if new_student.id in self._data:
            raise RepoException("Student is already in the list!")
        else:
            self._data[new_student.id] = new_student
    #adds a student to the list of students

    def get_student_id(self, student_id: str):
        try:
            return self._data[int(student_id)]
        except KeyError:
            raise RepoException("The given id does not correspond with any of the student's id in list!")

    def get_student_group(self, student_group: str):
        try:
            if int(student_group) in self._data:
                student = self._data
                return self._data[student.id]
        except KeyError:
            raise RepoException("No student is part of the given group!")

    def get_all(self):
        return list(self._data.values())
    #gets the list of students and returns it

    def delete_students_from_group(self, group: str):
        try:
            list_of_students = list(self._data.values())
            index = 0
            while index < len(list_of_students):
                if int(group) in list_of_students[index]:
                    list_of_students.remove(list_of_students[index])
                else:
                    index = index + 1
            return list_of_students

        except KeyError:
            raise RepoException("There is no student in the given group")
    #deletes the students from a specific group, written on the console


class TextFileRepository(MemoryRepository):
    #this class inherits from MemoryRepository
    #it has all the attributes and methods that MemoryRepository has

    def __int__(self, file_name="student.txt"):
        #call the superclass constructor
        super(TextFileRepository, self).__int__()
        #remember the name of the file we are working on
        self._file_name  = file_name
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
            new_student = student(current_student[0], current_student[1], current_student[2])
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

    def get_all(self):
        self._save_file()
        return super(TextFileRepository, self).get_all()

    def delete_students_from_group(self, group: str):
        super(TextFileRepository, self).delete_students_from_group(int(group))
        self._save_file()



class BinaryFileRepository(MemoryRepository):
    def __int__(self, file_name="student.bin"):
        super(BinaryFileRepository, self).__int__()
        self._file_name = file_name
        #load all students from the binary file
        self._load_file()

    def add_student(self, new_student: student):
        super(BinaryFileRepository, self).add_student(new_student)
        #save all the students to the binary file
        self._save_file()

    def get_all(self):
        self._save_file()
        return super(BinaryFileRepository, self).get_all()


    def delete_students_from_group(self, group: str):
        super(BinaryFileRepository, self).delete_students_from_group(int(group))
        self._save_file()

    def _load_file(self):
        # r - read, b - binary
        file_input = open(self._file_name, "rb")
        obj = pickle.load(file_input)

        for student in obj:
            super().add(student)
        file_input.close()

    def _save_file(self):
        # w - write mode (overwrite), b - binary mode
        file_output = open(self._file_name, "wb")
        pickle.dump(self.get_all(), file_output)
        file_output.close()


def generate_students():
    students_id = ["1212", "2323", "3434", "4545", "5656", "6767", "7878", "8989","9090", "10101"]
    students_names = ["Lavinia Grecu", "Tudor Dragu", "Steluta Luminita", "Popescu Ionela", "Amandina Trambulina",
                      "Carolina Jambala", "Bogdan Ionescu", "Ana Cotoran", "Havana Lua", "Vivi Ducan"]
    students_groups = ["911", "912", "913", "914", "915", "916", "917"]

    student_list = []
    for i in range(0,10):
        id = students_id[i]
        name = random.choice(students_names)
        group = random.choice(students_groups)

        student_list.append(student(id, name, group))

    return student_list
