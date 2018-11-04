"""
Given two arrays, write a function to compute their intersection.
"""
def intersect(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    mydict = {}
    res = []
    if(len(nums1) < len(nums2)):
        nums1 , nums2 = nums2, nums1
    for i in range(len(nums1)):
        if mydict.get(nums1[i]) == None:
            mydict[nums1[i]] = 1
        else:
            mydict[nums1[i]] += 1

    print(mydict)

    for i in range(len(nums2)):
        if mydict.get(nums2[i]) == None:
            continue
        else:
            res.append(nums2[i])
            if(mydict.get(nums2[i]) == 1):
                mydict.pop(nums2[i])
            else:
                mydict[nums2[i]] -= 1
    print(res)
    return res
