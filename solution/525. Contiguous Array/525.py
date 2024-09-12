class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        seen = {0: -1}
        res, presum = 0, 0
        for i in range(len(nums)):
            presum += 1 if nums[i] == 1 else -1
            if presum in seen:
                res = max(res, i - seen[presum])
            else:
                seen[presum] = i
        return res
    
