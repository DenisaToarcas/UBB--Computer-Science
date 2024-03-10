"""sum of even numbers found on even positions in a list"""

def sum_of_even_numbers_on_even_positions(list_of_no: list, original_positions: list):
    if len(list_of_no) != 1:
        mid = len(list_of_no)//2
        left_part_of_list = list_of_no[:mid]
        right_part_of_list = list_of_no[mid:]
        original_positions_left = original_positions[:mid]
        original_positions_right = original_positions[mid:]

        return sum_of_even_numbers_on_even_positions(left_part_of_list, original_positions_left) + sum_of_even_numbers_on_even_positions(right_part_of_list, original_positions_right)

    else:
        if list_of_no[0] % 2 == 0 and original_positions[0] % 2 == 0:
            return list_of_no[0]
        return 0


list = [0, 1, 2, 3, 4, 5, 6]
mid = len(list)//2
print(mid)
print(list[:mid])
print(list[mid:])
original_positions = [i for i in range(0, len(list))]
print(sum_of_even_numbers_on_even_positions(list, original_positions))


def permute_increasing_decreasing(n):
    nums = [i for i in range(0, n+1)]
    result = []

    def backtrack(start):
        if start == n:
            result.append(nums[:])
            return

        for i in range(start, n):
            if start == 0 or nums[i] > max(nums[:start]):
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start + 1)
                nums[start], nums[i] = nums[i], nums[start]

        for i in range(start + 1, n):
            if nums[i] < nums[start]:
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start + 1)
                nums[start], nums[i] = nums[i], nums[start]

    backtrack(0)
    return result

print(permute_increasing_decreasing(3))
