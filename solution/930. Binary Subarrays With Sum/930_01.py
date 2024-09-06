class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        seen = defaultdict(int)
        seen[0] = 1
        res, prefix = 0, 0
        for x in nums:
            prefix += x
            if prefix - goal in seen:
                res += seen[prefix - goal]
            seen[prefix] += 1
        return res
    
