class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        jmin = jmax = boundary = -1
        
        for i in range(len(nums)):
            if nums[i] < minK or maxK < nums[i]:
                boundary = i
            if nums[i] == minK:
                jmin = i
            if nums[i] == maxK:
                jmax = i
            res += max(0, min(jmin, jmax) - boundary)
            
        return res
    
