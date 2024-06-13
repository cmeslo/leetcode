class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = len(matrix), len(matrix[0])
        for i in range(1, m):
            for j in range(0, n):
                matrix[i][j] += matrix[i - 1][j]
        
        res = 0
        for y2 in range(m):
            for y1 in range(0, y2 + 1):
                cnt = {0: 1}
                presum = 0
                for x in range(n):
                    presum += matrix[y2][x] - (matrix[y1 - 1][x] if y1 > 0 else 0)
                    res += cnt.get(presum - target, 0)
                    cnt[presum] = cnt.get(presum, 0) + 1
        return res
    
