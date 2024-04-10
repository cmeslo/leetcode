class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        mn1, mn2, mx1, mx2 = 10**9, 10**9, 0, 0
        
        for x in nums:
            if x > mx1:
                mx1, mx2 = x, mx1
            elif x > mx2:
                mx2 = x
            
            if x < mn1:
                mn1, mn2 = x, mn1
            elif x < mn2:
                mn2 = x
        
        return mx1 * mx2 - mn1 * mn2
    
