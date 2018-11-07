"""
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
"""
def isPalindrome(self, x):
    """
    :type x: int
    :rtype: bool
    """ 
    res = True
    if x > 0:
        number = x
        reverse = 0 
        while number > 0:
            reverse = reverse*10 + number%10
            number = number//10
        number = x
        while number > 0 and reverse > 0:
            if number%10 != reverse%10:
                res = False
                break
            number = number//10
            reverse = reverse//10
        return res
    elif x < 0:
        return False
        number = -1*x
        reverse = 0
        while number > 0:
            reverse = reverse*10 + number%10
            number = number//10
        number = -1*x
        
        #print(number, reverse)
        
        while number > 0 and reverse > 0:
            if number%10 != reverse%10:
                res = False
                break
            number = number//10
            reverse = reverse//10
        return res
    else:
        return True
    
    
        
    
    