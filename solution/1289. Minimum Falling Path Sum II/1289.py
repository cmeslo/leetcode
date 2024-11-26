class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        for prev_row, cur_row in pairwise(grid):
            mn1, mn2 = nsmallest(2, prev_row)
            for j, pre in enumerate(prev_row):
                cur_row[j] += mn1 if pre != mn1 else mn2
        return min(grid[-1])
    
