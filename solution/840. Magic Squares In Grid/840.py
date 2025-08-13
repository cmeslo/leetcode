class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
    
        target = 0
        for i in range(1, 10):
            target |= (1 << i)

        def is_magic(i, j, target):
            for y in range(i, i + 3):
                for x in range(j, j + 3):
                    target ^= (1 << grid[y][x])
            if target != 0:
                return False

            s = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]
            if grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s:
                return False

            for y in range(i, i + 3):
                if grid[y][j] + grid[y][j+1] + grid[y][j+2] != s:
                    return False
            for x in range(j, j + 3):
                if grid[i][x] + grid[i+1][x] + grid[i+2][x] != s:
                    return False
            return True
    
        res = 0
        for i in range(m - 2):
            for j in range(n - 2):
                if is_magic(i, j, target):
                    res += 1
        return res
    
