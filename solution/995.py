class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        diff = [0] * (n + 1)
        res = presum = 0
        
        for i in range(n):
            if (presum + diff[i] + nums[i]) % 2 == 0:
                if i + k > n:
                    return -1
                diff[i] += 1
                diff[i + k] -= 1
                res += 1
            presum += diff[i]
        
        return res
