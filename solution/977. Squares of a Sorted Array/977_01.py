class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        l, r = 0, n - 1
        for i in range(n - 1, -1, -1):
            L = nums[l] * nums[l]
            R = nums[r] * nums[r]
            if L > R:
                res[i] = L
                l += 1
            else:
                res[i] = R
                r -= 1
        return res
    
