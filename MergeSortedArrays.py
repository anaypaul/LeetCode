"""
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
"""
def merge(self, nums1, m, nums2, n):
    """
    :type nums1: List[int]
    :type m: int
    :type nums2: List[int]
    :type n: int
    :rtype None
    """
    res = []
    i = 0
    j = 0
    while(i<m and j < n):
        if nums1[i] <= nums2[j]:
            res.append(nums1[i])
            i+=1
        else:
            res.append(nums2[j])
            j+=1
    while(i<m):
        res.append(nums1[i])
        i+=1
        
    while(j<n):
        res.append(nums2[j])
        j+=1

    for i in range(len(res)):
        nums1[i] = res[i]