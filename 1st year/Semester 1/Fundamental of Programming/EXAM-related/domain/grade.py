class Grade:
    def __init__(self, studentID: int, laboratory_number: int, laboratoryProblem: int, value: int):
        self.__studentID = studentID
        self.__laboratory_number = laboratory_number
        self.__laboratoryProblem = laboratoryProblem
        self.__value = value

    def __repr__(self):
        return str(self)

    def __str__(self):
        return str(self.__studentID) + " " + str(self.__laboratory_number) + " " + str(self.__laboratoryProblem) + " " \
               + str(self.__value)

    @property
    def studentID(self):
        return self.__studentID

    @property
    def laboratory_number(self):
        return self.__laboratory_number

    @laboratory_number.setter
    def laboratory_number(self, new_lab: int):
        self.__laboratory_number = new_lab

    @property
    def laboratoryProblem(self):
        return self.__laboratoryProblem

    @laboratoryProblem.setter
    def laboratoryProblem(self, new_problem: int):
        self.__laboratoryProblem = new_problem

    @property
    def value(self):
        return self.__value

    @value.setter
    def value(self, new_grade: int):
        self.__value = new_grade
