class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        res = 0
        prod, i = 1, 0
        for j in range(len(nums)):
            prod *= nums[j]
            while i <= j and prod >= k:
                prod = prod // nums[i]
                i += 1
            res += j - i + 1
        return res
    
