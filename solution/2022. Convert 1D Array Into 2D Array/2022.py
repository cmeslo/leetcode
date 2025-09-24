class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        
        res = [[0] * n for _ in range(m)]
        k = 0
        for i in range(m):
            for j in range(n):
                res[i][j] = original[k]
                k += 1
        return res
    
