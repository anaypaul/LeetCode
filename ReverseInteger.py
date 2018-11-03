"""
Given a 32-bit signed integer, reverse digits of an integer.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""
def reverse(x):
    """
    :type x: int
    :rtype: int
    """
    reversed_number = 0
    if(x >= 0):
        reversed_number = 0
        while(x > 0):
            reversed_number = reversed_number*10 + x%10
            x = x//10
    else:
        x = x*-1
        reversed_number = 0
        while(x > 0):
            reversed_number = reversed_number*10 + x%10
            x = x//10
        reversed_number = reversed_number*-1
    if reversed_number < -2**31 or reversed_number > 2**31:
        return 0
    else:
        return reversed_number