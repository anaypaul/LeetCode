"""
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
"""
def hammingDistance(self, x, y):
    """
    :type x: int
    :type y: int
    :rtype: int
    """
    ans = 0
    while(x>0 and y>0):
        if (x&1) != (y&1):
            ans += 1
        x = x>>1
        y = y>>1
    
    while(x >0):
        if (x&1) == 1:
            ans += 1
        x = x >>1
    while(y >0):
        if (y&1) == 1:
            ans +=1
        y = y>>1
    return ans