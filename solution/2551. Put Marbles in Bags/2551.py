class Solution:
    def putMarbles(self, w: List[int], k: int) -> int:
        A = sorted(w[i] + w[i + 1] for i in range(len(w) - 1))
        return sum(A[len(A) - k + 1:]) - sum(A[:k - 1])
