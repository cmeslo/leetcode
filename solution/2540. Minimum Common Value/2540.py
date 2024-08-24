class Solution:
    def getCommon(self, A: List[int], B: List[int]) -> int:
        i, j = 0, 0
        m, n = len(A), len(B)
        while i < m and j < n:
            if A[i] == B[j]:
                return A[i]
            if A[i] < B[j]:
                i += 1
            else:
                j += 1
        return -1
    
