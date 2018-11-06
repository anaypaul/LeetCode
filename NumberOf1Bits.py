"""
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
"""
def hammingWeight(self, n):
    """
    :type n: int
    :rtype: int
    """
    ans = 0
    while(n > 0):
        if (n & 1 == 1):
            ans += 1
        n = n>>1
    
    return ans