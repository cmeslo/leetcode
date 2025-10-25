class Solution:
    def xorQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        for i in range(len(A) - 1):
            A[i + 1] ^= A[i]
        return [A[i - 1] ^ A[j] if i else A[j] for i, j in queries]
    
