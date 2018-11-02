"""
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
"""
def strStr(haystack, needle):
    """
    :type haystack: str
    :type needle: str
    :rtype: int
    """
    if(len(haystack)> 0 and len(needle)>0):
        if(len(haystack) >= len(needle)):
            ans = -1
            i=0
            while(i<=len(haystack)-len(needle)):
                if needle[0] == haystack[i]:
                    j = i
                    ans = j
                    for k in range(len(needle)):
                        if needle[k] == haystack[j]:
                            j +=1
                        else:
                            break
                        if k == len(needle) - 1:
                            return ans
                i+=1
            return -1
        else:
            return -1
    elif(len(haystack)==0 and len(needle)>0):
        return -1
    else:
        return 0