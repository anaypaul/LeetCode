"""
Given two strings s and t , write a function to determine if t is an anagram of s.
"""
def isAnagram(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: bool
    """
    _hash = [0]*26
    for each in s:
        _hash[ord(each)%26] += 1
    
    for each in t:
        _hash[ord(each)%26] -= 1
    
    for i in range(len(_hash)):
        if _hash[i] !=0:
            return False
    return True