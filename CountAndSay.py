"""
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
"""
def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = "1"
        while(n-1 > 0):
            x = ""
            i = 0
            while(i < len(result)):
                count = 1
                j = i + 1
                while(j < len(result) and result[j] == result[i]):
                    count += 1
                    j += 1
                i = j
                x = x + str(count) + result[j-1]
            result = x
            n -= 1
        return result