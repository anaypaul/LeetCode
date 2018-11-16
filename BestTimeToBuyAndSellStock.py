"""
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one
"""
def maxProfit(prices):
    """
    :type prices: List[int]
    :rtype: int
    """
    ans = 0
    if len(prices) <= 1:
        return 0
    else:
        minimum = prices[0]
        for i in range(1,len(prices),1):
            if prices[i] < minimum:
                minimum = prices[i]
            val = max(0, prices[i] - minimum)
            if ans < val:
                ans = val
        return ans