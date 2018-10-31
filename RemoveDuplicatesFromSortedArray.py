"""
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
"""

def removeDuplicates(arr):
    """
    :type arr: List[int]
    :rtype: int
    """
    if(len(arr)==0):
            return 0
    else:
        index = 0
        prev = 0
        for i in range(1,len(arr)):
            if(arr[i] == arr[prev]):
                continue
            else:
                arr[index+1] = arr[i]
                prev = i
                index += 1
        return index+1
