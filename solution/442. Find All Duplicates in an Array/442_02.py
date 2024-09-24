class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            while nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        
        res = []
        for i, x in enumerate(nums):
            if x != i + 1:
                res.append(x)
        return res
    
