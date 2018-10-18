"""
Find First and Last Position of Element in Sorted Array
"""
def searchRange(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    if len(nums)>1:
        first = -1 
        second = -1
        for i in range(len(nums)):
            if nums[i] == target :
                if first == -1 and second == -1:
                    first = i
                    second = i
                elif first != -1 and second == -1:
                    second = i
                else:
                    second = i
        return [first, second]
    elif len(nums) == 1:
        if nums[0] == target:
            return [0,0]
        else:
            return [-1,-1]
    else:
        return [-1,-1]