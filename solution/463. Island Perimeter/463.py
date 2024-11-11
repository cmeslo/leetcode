class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = [0, 1, 0, -1, 0]
        
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 1:
                    continue
                for k in range(4):
                    y = i + dirs[k]
                    x = j + dirs[k + 1]
                    if y < 0 or y >= m or x < 0 or x >= n or grid[y][x] == 0:
                        res += 1
        return res
