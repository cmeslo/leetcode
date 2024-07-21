class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res, i = 0, 0
        for x in nums:
            res = res ^ x ^ i
            i += 1
        return res ^ i
    
