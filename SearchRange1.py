"""
Find First and Last Position of Element in Sorted Array
"""
def bSearch(arr, target):
    index_left = -1
    index_right = -1
    low = 0
    high = len(arr) -1 
    while(low<=high):
        mid = int((low + high)/2)
        if arr[mid] == target:
            index_left = mid
            high = mid - 1
        elif arr[mid] < target:
            low = mid + 1
        elif arr[mid] > target:
            high = mid -1
    low = 0
    high = len(arr) -1 
    while(low<=high):
        mid = int((low + high)/2)
        if arr[mid] == target:
            index_right = mid
            low = mid + 1
        elif arr[mid] < target:
            low = mid + 1
        elif arr[mid] > target:
            high = mid -1
    return [index_left,index_right]