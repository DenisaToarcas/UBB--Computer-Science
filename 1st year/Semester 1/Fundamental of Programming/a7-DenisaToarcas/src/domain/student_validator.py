from src.domain.student import student
from src.domain.exceptions import StudentValidationException

class StudentValidator:
    @staticmethod
    def is_group_part_of_the_university(group: int):
        """
        We check wether the group assigned to the student is part of the current university
        Possible groups: 911, 912, 913, 914, 915, 916, 917
        """

        possible_groups = [911, 912, 913, 914, 915, 916, 917]
        if group in possible_groups:
            return True
        else:
            return False

    @staticmethod
    def is_id_valid_or_not(id: int):
        """
        An id is valid if it is formed by at least 2 digits
        """

        return id / 100 == 0

    def validator(self, student_to_verify: student):
        error_list=[]
        if StudentValidator.is_group_part_of_the_university(student_to_verify.group) == False:
            error_list.append("The group assigned to the student is not part of our university!")
        if StudentValidator.is_id_valid_or_not(student_to_verify.id) == False:
            error_list.append("The id of the student is not valid!")

        if len(error_list) > 0:
            raise StudentValidationException(error_list)

