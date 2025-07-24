class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ones = nums.count(1)
        n = res = len(nums)
        j = cnt = 0
        for i in range(n):
            while j - i < ones:
                cnt += nums[j % n]
                j += 1
            res = min(res, ones - cnt)
            cnt -= nums[i]
        return res
    
