class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        val, cnt = 0, 0
        for x in nums:
            if cnt == 0:
                val = x
                cnt = 1
            else:
                cnt += 1 if val == x else -1
        return val
    
