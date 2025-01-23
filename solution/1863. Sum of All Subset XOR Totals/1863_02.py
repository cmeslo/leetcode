class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for state in range(1 << n):
            x = 0
            for i in range(n):
                if state & 1:
                    x ^= nums[i]
                state >>= 1
            res += x
        return res
    
