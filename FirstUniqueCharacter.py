"""
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
"""
def firstUniqChar(s):
    """
    :type s: str
    :rtype: int
    """
    ans = -1
    freq = [0]*26
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
    for i in range(len(s)):
        if freq[ord(s[i]) - ord('a')] == 1:
            ans = i
            break
    return ans
            