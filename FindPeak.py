def getPivot(arr):
    """
    This method gets the index of the element from where the array has be rotated.
    ie the pivot element.
    The idea is to get the pivot location in the array and split the array into 2 to search
    for the target element in the 2 arrays.
    """
    low = 0
    high = len(arr) - 1
    while(low <= high):
        mid = int((low + high)/2)
        if mid+1 < len(arr) and arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]: 
            break
        elif mid+1 < len(arr) and arr[mid-1] > arr[mid+1]:
            high = mid -1
        else:
            low = mid + 1
    return mid
def binarySearch(arr,low, high, key):
    if(low<=high):
        mid = int((low + high)/2)
        if arr[mid] == key:
            return mid
        elif arr[mid] > key:
            return binarySearch(arr, low, mid-1,key)
        elif arr[mid] < key:
            return binarySearch(arr, mid+1, high,key)
    else:
        return -1
def search(arr, target):
    """
    This is the method that searches for a target element in the sorted and rotated array.
    """
    pivot_index = getPivot(arr)
    
    left = arr[:pivot_index+1]
    right = arr[pivot_index+1:]
    ans_left = binarySearch(left, 0,len(left)-1,target)
    ans_right = binarySearch(right, 0, len(right)-1,target)
    if ans_left == -1 and ans_right == -1:
        return -1
    elif ans_left != -1 and ans_right == -1:
        return ans_left
    else:
        return ans_right + len(left)


