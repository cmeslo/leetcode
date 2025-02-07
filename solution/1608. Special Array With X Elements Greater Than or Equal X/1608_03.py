class Solution:
    def specialArray(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        while l <= r:
            m = l + (r - l) // 2
            cnt = sum(x >= m for x in nums)
            if cnt == m:
                return cnt
            elif cnt > m:
                l = m + 1
            elif cnt < m:
                r = m - 1
        return -1
