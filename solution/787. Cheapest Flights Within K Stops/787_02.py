class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        K += 1
        dp = [[inf] * (K + 1) for _ in range(n)]
        dp[src][0] = 0
        for k in range(1, K + 1):
            dp[src][k] = 0
            for f in flights:
                [a, b, cost] = f;
                dp[b][k] = min(dp[b][k], dp[a][k - 1] + cost)
        return dp[dst][K] if dp[dst][K] != inf else -1
    
