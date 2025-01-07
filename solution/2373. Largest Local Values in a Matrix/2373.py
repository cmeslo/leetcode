class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        
        res = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                for y in range(i, i + 3):
                    for x in range(j, j + 3):
                        res[i][j] = max(res[i][j], grid[y][x])
        return res
    
