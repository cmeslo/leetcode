class Solution:
    def average(self, salary: List[int]) -> float:
        total, mn, mx = 0.0, math.inf, -math.inf
        for x in salary:
            mn, mx = min(mn, x), max(mx, x)
            total += x
        return (total - mn - mx) / (len(salary) - 2)

