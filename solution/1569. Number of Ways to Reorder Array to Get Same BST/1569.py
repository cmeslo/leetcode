class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        def ways(nums):
            if len(nums) <= 2: return 1
            l = [x for x in nums if x < nums[0]]
            r = [x for x in nums if x > nums[0]]
            return comb(len(l) + len(r), len(l)) * ways(l) * ways(r) % (10**9 + 7)
        return ways(nums) - 1
