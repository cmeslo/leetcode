class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        onesRow = [0] * m
        onesCol = [0] * n
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    onesRow[i] += 1
                    onesCol[j] += 1
        
        res = [[0] * n for i in range(m)]
        for i in range(m):
            for j in range(n):
                res[i][j] = 2*onesRow[i] + 2*onesCol[j] - m - n
        return res
    
