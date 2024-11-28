class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m, n = len(ring), len(key)

        letter2pos = {ch: [] for ch in set(ring)}
        for i, ch in enumerate(ring):
            letter2pos[ch].append(i)

        dp = [[float('inf')]*m for _ in range(n)]

        for pos in letter2pos[key[0]]:
            dp[0][pos] = min(pos, m - pos)

        for i in range(1, n):
            for pos in letter2pos[key[i]]:
                for pre_pos in letter2pos[key[i-1]]:
                    diff = abs(pos - pre_pos)
                    dp[i][pos] = min(dp[i][pos], dp[i - 1][pre_pos] + min(diff, m - diff))

        res = sys.maxsize
        for pos in letter2pos[key[n-1]]:
            res = min(res, dp[n - 1][pos])

        return res + n
    
