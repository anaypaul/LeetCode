"""
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
"""

def missingNumber(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if len(nums) == 0:
        return 0
    else:
        freq = 0
        for each in nums:
            freq = freq | 1<<(each)

        s = str(bin(freq)[2:])
        s = s[::-1]
        for i in range(len(s)):
            if s[i] == '0':
                return i
        return len(nums)
