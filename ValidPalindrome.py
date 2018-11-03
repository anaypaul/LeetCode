"""
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
"""
def isPalindrome(s):
    """
    :type s: str
    :rtype: bool
    """
    characters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9']
    low = 0
    high = len(s) - 1
    s = s.lower()
    while(low <= high):
        if s[low] in characters and s[high] in characters:
            if s[low] == s[high]:
                low += 1
                high -= 1
            else:
                return False
        else:
            if s[low] in characters and s[high] not in characters:
                high -= 1
            elif s[low] not in characters and s[high] in characters:
                low += 1
            else:
                low += 1
                high -= 1
    return True
        