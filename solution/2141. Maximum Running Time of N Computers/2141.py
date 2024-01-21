class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        l, r = 0, sum(batteries)
        while l < r:
            x = (l + r + 1) // 2
            if n * x <= sum(min(x, b) for b in batteries):
                l = x
            else:
                r = x - 1
        return l
