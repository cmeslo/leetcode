class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix[0])
        
        for i in range(1, n):
            for j in range(n):
                val = matrix[i][j]
                matrix[i][j] = inf
                for k in range(max(0, j - 1), min(n - 1, j + 1) + 1):
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][k] + val)
        
        return min(matrix[-1])
    
