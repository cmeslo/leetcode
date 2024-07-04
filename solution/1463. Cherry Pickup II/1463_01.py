class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        @lru_cache(None)
        def dfs(y, x1, x2):
            if y == m:
                return 0
            
            cherry = 0
            for i in range(max(0, x1-1), min(n-1, x1+1) + 1):
                for j in range(max(0, x2-1), min(n-1, x2+1) + 1):
                    cherry = max(cherry, dfs(y + 1, i, j))
            return cherry + grid[y][x1] + (x1 != x2) * grid[y][x2]
        
        return dfs(0, 0, n - 1)
    
