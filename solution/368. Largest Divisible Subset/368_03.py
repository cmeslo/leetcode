class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        l = 0
        idx = 0
        dp = [0] * n
        prev = [-1] * n
        for i in range(n):
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    prev[i] = j
            if dp[i] > l:
                l = dp[i]
                idx = i
        
        res = []
        while idx != -1:
            res.append(nums[idx])
            idx = prev[idx]
        return res
    
