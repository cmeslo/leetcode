class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        def atMost(k):
            res = j = 0
            for i in range(len(nums)):
                k -= nums[i] % 2
                while k < 0:
                    k += nums[j] % 2
                    j += 1
                res += i - j + 1
            return res
        
        return atMost(k) - atMost(k - 1)
    
