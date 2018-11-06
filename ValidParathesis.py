"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
"""
def isValid(self, s):
    """
    :type s: str
    :rtype: bool
    """
    st = []
    for each in s:
        if each == "(" or each == "{" or each =="[" :
            st.append(each)
        else:
            if len(st) >=1 and st[-1]== "(" and each == ")":
                st.pop()
            elif len(st) >=1 and st[-1] == "{" and each == "}" :
                st.pop()
            elif len(st) >=1 and st[-1] == "[" and each == "]" :
                st.pop()
            else:
                return False
    if len(st) == 0:
        return True
    else:
        return False