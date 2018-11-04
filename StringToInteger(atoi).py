"""
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
"""
def atoi(string):
    """
    :type str: str
    :rtype: int
    """
    string=string.strip().replace(" ","*")
    if len(string)==0:
        return 0
    else:
        ans = 0
        sign = 1
        if string[0] == "-":
            sign = -1
        elif string[0] == "+":
            sign = 1
        elif string[0] in ['0','1','2','3','4','5','6','7','8','9']:
            ans = int(string[0])
        else:
            return ans
        for i in range(1,len(string)):
            if string[i] == ".":
                break
            if string[i] == "+" and ans == 0:
                sign = 1
                return ans * -1
            if string[i] == "-" and ans == 0:
                sign = -1
                return ans * -1
            if string[i] in ['0','1','2','3','4','5','6','7','8','9']:
                ans = ans*10 + int(string[i])
            else:
                break
        if ans < -2147483648 or ans > 2147483647:
            if sign == -1:
                return -2147483648
            else:
                return 2147483647
        else:
            return ans*sign