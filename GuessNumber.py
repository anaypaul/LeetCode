"""You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):"""
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 0
        high = n
        ans = 0
        while(low<=high):
            mid = (low+high)//2
            if guess(mid) == 0:
                ans = mid
                break
            elif guess(mid) == -1:
                high = mid - 1
                ans = mid
            elif guess(mid) == 1:
                low = mid + 1
        return ans