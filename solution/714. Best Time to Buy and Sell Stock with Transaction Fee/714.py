class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        hold, sold = -10**9, 0
        for x in prices:
            pre_hold = hold
            hold = max(hold, sold - x)
            sold = max(sold, pre_hold + x - fee)
        return sold
