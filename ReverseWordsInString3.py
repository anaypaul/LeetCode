# Reverse Words in a String III
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        x = s.split(" ")
        res = []
        for each in x:
            res.append(each[::-1])
        return " ".join(res).replace("  "," ")