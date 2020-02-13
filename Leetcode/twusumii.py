class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        length = len(numbers)
        while i < length:
            n1 = numbers[i]
            n2 = target - n1
            if n2 in numbers[i + 1:]:
                return [i + 1, numbers[i+1:].index(n2) + i + 2]
            i += numbers.count(n1)