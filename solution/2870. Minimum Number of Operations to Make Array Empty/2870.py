class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mp = Counter(nums)
        
        res = 0
        for cnt in mp.values():
            if cnt == 1: return -1
            res += cnt // 3 + (cnt % 3 > 0)
        return res
    
