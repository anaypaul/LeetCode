"""
Given an array, rotate the array to the right by k steps, where k is non-negative.
"""
def rotate(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: void Do not return anything, modify nums in-place instead.
    """
    # Pythonic solution
    k = k % len(nums)
    nums[0:k], nums[k:] = nums[-k:] , nums[:len(nums)-k]
    return nums