class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m, n, mod = len(grid), len(grid[0]), 10 ** 9 + 7
        
        @lru_cache(None)
        def dfs(i, j):
            res = 1
            for y, x in [[i, j + 1], [i, j - 1], [i + 1, j], [i - 1, j]]:
                if 0 <= y < m and 0 <= x < n and grid[i][j] < grid[y][x]:
                    res += dfs(y, x) % mod
            return res
        return sum(dfs(i, j) for i in range(m) for j in range(n)) % mod
