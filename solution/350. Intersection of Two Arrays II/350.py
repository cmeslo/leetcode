class Solution:
    def intersect(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        B.sort()
        
        res = []
        i = j = 0
        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                i += 1
            elif B[j] < A[i]:
                j += 1
            else:
                res.append(A[i])
                i += 1
                j += 1
        return res
