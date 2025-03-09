class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        m = {0: -1}
        x = 0
        for i in range(len(nums)):
            x = (x + nums[i]) % k
            if x in m:
                if i - m[x] > 1:
                    return True
            else:
                m[x] = i
        return False
    
