class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        mn1, mn2 = 101, 101
        
        for x in prices:
            if x < mn1:
                mn1, mn2 = x, mn1
            elif x < mn2:
                mn2 = x
        
        return money - mn1 - mn2 if money >= mn1 + mn2 else money
    
