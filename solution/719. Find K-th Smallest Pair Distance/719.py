class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        
        l, r = 0, nums[-1] - nums[0]
        while l < r:
            mid = (l + r) // 2
            if self.countSmallerOrEqual(nums, mid) < k:
                l = mid + 1
            else:
                r = mid
        return l
    
    def countSmallerOrEqual(self, A: List[int], x: int) -> int:
        cnt = 0
        for i in range(len(A)):
            r = bisect.bisect_right(A, A[i] + x, i + 1) - 1
            cnt += r - i
        return cnt
