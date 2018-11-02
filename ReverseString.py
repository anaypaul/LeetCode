def reverseString(self, s):
    """
    :type s: str
    :rtype: str
    """
    #pythonic solution
    #return s[::-1]
    
    #other solution
    ans = ""
    for i in range(len(s)-1,-1,-1):
        ans += s[i]
    return ans