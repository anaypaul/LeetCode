"""
This is the work area for writing new methods for the problem I am currently working on.
"""
def binarySearch(arr, low, high, key):
    if(low <= high):
        mid = int((low + high)/2)
        print("mid", mid)
        if arr[mid] == key:
            return mid
        elif key > arr[mid]:
            return binarySearch(arr, mid + 1, high, key)
        elif key < arr[mid]:
            return binarySearch(arr, low, mid - 1, key)
    else:
        return -1

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