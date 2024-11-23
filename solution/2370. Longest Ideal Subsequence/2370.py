class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        res = 0
        A = [0]*26
        for i in range(n):
            a = ord(s[i]) - ord('a')
            cnt = 0
            for j in range(max(0, a - k), min(25, a + k) + 1):
                cnt = max(cnt, A[j] + 1)
            A[a] = max(A[a], cnt)
            res = max(res, A[a])
        return res
