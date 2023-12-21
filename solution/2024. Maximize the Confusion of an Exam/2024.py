class Solution:
    def maxConsecutiveAnswers(self, A: str, k: int) -> int:
        def cnt(k: int, key: str) -> int:
            res, i = 0, 0
            for j in range(len(A)):
                if A[j] == key:
                    k -= 1
                    while k < 0:
                        if A[i] == key:
                            k += 1
                        i += 1
                res = max(res, j - i + 1)
            return res
        return max(cnt(k, 'T'), cnt(k, 'F'))
