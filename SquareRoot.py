def sqrt(x):
    ans = 0
    low = 0
    high = x
    while(low <= high):
        mid = int((low + high)/2)
        if mid*mid == x:
            ans = mid
            break
        elif mid*mid < x:
            low = mid + 1
            ans = mid
        else:
            high = mid - 1 
    return ans