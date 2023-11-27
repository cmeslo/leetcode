class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        res = [-1] * len(nums)
        l = k + k
        s = 0
        for i, x in enumerate(nums):
            s += x
            if i >= l:
                res[i - k] = s // (l + 1)
                s -= nums[i - l]
        return res
