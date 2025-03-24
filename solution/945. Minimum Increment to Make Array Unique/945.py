class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        res = need = 0
        for x in sorted(nums):
            res += max(need - x, 0)
            need = max(need, x) + 1
        return res
    
