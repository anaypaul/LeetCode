"""
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
"""

def SingleNumber(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    ans = 0
    for i in range(len(nums)):
        ans = ans ^ nums[i]
    return ans