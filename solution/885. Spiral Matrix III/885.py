class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, y: int, x: int) -> List[List[int]]:
        res = []
        dy, dx = 0, 1
        
        n = 0
        while len(res) < rows * cols:
            for i in range(n // 2 + 1):
                if 0 <= y < rows and 0 <= x < cols:
                    res.append([y, x])
                y, x = y + dy, x + dx
            dy, dx = dx, -dy
            n += 1
            
        return res
    
