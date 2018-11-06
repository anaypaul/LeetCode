"""
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
"""
def generate(numRows):
    """
    :type numRows: int
    :rtype: List[List[int]]
    """
    result = []
    ll = []
    if numRows == 0:
        return result
    elif numRows == 1:
        ll.append(1)
        result.append(ll)
    else:
        ll.append(1)
        result.append(ll)
        for _ in range(numRows-1):
            x = ll
            ll = []
            ll.append(1)
            for j in range(len(x)-1):
                ll.append(x[j]+x[j+1])
            ll.append(1)
            result.append(ll)
    return result
    