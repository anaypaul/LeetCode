"""Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct."""

def ContainsDuplicate(arr):
    """
    :type nums: List[int]
    :rtype: bool
    """
    mydict = {}
    for i in range(len(arr)):
        if mydict.get(arr[i]) == 1:
            return True
        else:
            mydict[arr[i]] = 1
    return False

    """Use the below code when we know that the number will be within a given memory"""
    # check_postive = 0
    # check_negative = 0
    # for i in range(len(arr)):
    #     if(arr[i]<0):
    #         arr[i] = -1*arr[i]
    #         if( (check_negative & (1<<arr[i])) >0 ):
    #             return True
    #         else:
    #             check_negative = check_negative | (1<<arr[i])
    #     else:
    #         if( (check_postive & (1<<arr[i])) >0 ):
    #             return True
    #         else:
    #             check_postive = check_postive | (1<<arr[i])
    # return False
        