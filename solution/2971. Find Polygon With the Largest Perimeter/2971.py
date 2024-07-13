class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        
        res, cur = -1, 0
        for x in nums:
            if cur > x:
                res = cur + x
            cur += x
        return res
    
