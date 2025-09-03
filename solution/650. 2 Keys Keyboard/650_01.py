class Solution:
    def minSteps(self, n: int) -> int:
        if n <= 1:
            return 0
        
        for d in range(2, n):
            if n % d == 0:
                return self.minSteps(n // d) + d
        return n
    
