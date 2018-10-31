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
    profit = 0
        i = len(prices) - 1
        while(i>=0):
            if( i-1 >=0 and prices[i] > prices[i-1]):
                sell = prices[i]
                i = i - 1
                while(i-1>=0 and prices[i] > prices[i-1]  ):
                    i = i - 1
                buy = prices[i]
                profit +=  sell-buy
            i=i-1
        return profit