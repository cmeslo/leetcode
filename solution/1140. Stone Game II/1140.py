class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suf = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] + piles[i]
    
        @cache
        def solve(i, M):
            if i >= n:
                return 0
            
            res = presum = 0
            for x in range(1, 2*M + 1):
                if i + x - 1 >= n:
                    break
                presum += piles[i + x - 1]
                res = max(res, presum + suf[i + x] - solve(i + x, max(x, M)))
            return res
        
        return solve(0, 1)
    
