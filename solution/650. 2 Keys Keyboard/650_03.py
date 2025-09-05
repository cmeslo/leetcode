class Solution:
    def minSteps(self, n: int) -> int:
        res = 0
        for d in range(2, n + 1):
            while n % d == 0:
                n //= d
                res += d
        return res
    
