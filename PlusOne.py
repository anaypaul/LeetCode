"""
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
"""
def plusOne(digits):
    """
    :type digits: List[int]
    :rtype: List[int]
    """
    carry = 0
    digits[len(digits)-1] = digits[-1] + 1 + carry
    if digits[-1] > 9:
        carry = 1
        digits[-1] = digits[-1]%10
    for i in range(len(digits)-2,-1,-1):
        if digits[i] + carry > 9:
            carry =1 
            digits[i] = (digits[i]+carry)%10
        else:
            digits[i] = digits[i]  + carry
            carry = 0
    if carry == 0:
        return digits
    else:
        return [carry] + digits
            