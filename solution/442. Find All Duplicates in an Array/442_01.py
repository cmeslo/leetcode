class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            idx = abs(x) - 1
            if nums[idx] < 0:
                res.append(idx + 1)
            else:
                nums[idx] = -nums[idx]
        return res
    
