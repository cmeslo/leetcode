class Solution:
    def pivotInteger(self, n: int) -> int:
        total = n * (1 + n) // 2
        presum = 0
        for x in range(1, n + 1):
            presum += x
            if presum == total - presum + x:
                return x
        return -1
        
