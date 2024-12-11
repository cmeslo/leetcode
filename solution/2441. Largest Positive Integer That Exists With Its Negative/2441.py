class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        res = -1
        for x in nums:
            if -x in s:
                res = max(res, abs(x))
        return res
    
