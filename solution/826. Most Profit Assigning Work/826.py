class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        A = sorted(zip(difficulty, profit))
        res = i = mx = 0
        for w in sorted(worker):
            while i < len(A) and A[i][0] <= w:
                mx = max(mx, A[i][1])
                i += 1
            res += mx
        return res
    
