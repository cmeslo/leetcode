class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        def atMost(val):
            if val < 0: return 0
            res = i = 0
            for j in range(len(nums)):
                val -= nums[j]
                while val < 0:
                    val += nums[i]
                    i += 1
                res += j - i + 1
            return res
        
        return atMost(goal) - atMost(goal - 1)
    
