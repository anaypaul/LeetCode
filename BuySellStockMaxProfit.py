"""
Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
"""
def maxProfit(self, prices):
    """
    :type prices: List[int]
    :rtype: int
    """
    growth = [0]*len(prices)
    for i in range(1,len(prices)):
        if prices[i] > prices[i-1]:
            growth[i] = 1
    
    profit = 0
    i = len(prices) - 1
    while(i>=0):
        if growth[i]==1:
            sell=prices[i]
            while(growth[i]!=0 and i>=0):
                i = i - 1
            buy = prices[i]
            profit += sell - buy
        i = i - 1
    return profit
