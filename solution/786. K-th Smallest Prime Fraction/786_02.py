class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], k: int) -> List[int]:
        n = len(A)
        a, b = 0, 0

        l, r = 0, 1
        while l < r:
            m = (l + r) / 2

            f_max = 0
            count = 0
            j = 0
            for i in range(n):
                while j < n and A[i] > m * A[j]:
                    j += 1
                if j == n:
                    break
                count += n - j
                f = A[i] / A[j]
                if f > f_max:
                    f_max = f
                    a, b = i, j

            if count == k:
                return [A[a], A[b]]
            elif count < k:
                l = m
            else:
                r = m
        return []
