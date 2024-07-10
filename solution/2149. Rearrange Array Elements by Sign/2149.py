class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        i, j = 0, 1
        for x in nums:
            if x > 0:
                res[i] = x
                i += 2
            else:
                res[j] = x
                j += 2
        return res
    
