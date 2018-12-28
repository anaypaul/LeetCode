class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        x = s.strip().split()[::-1]
        ans = " ".join(x)
        return ans