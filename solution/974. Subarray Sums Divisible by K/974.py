class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        m = [0] * k
        m[0] = 1
        res, presum = 0, 0
        for x in nums:
            presum = (presum + x % k + k) % k
            res += m[presum]
            m[presum] += 1
        return res
    
