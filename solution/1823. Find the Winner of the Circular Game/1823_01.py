class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        if k == 1: return n
        
        nxt = [0] * n
        for i in range(n - 1):
            nxt[i] = i + 1
        nxt[n - 1] = 0
        
        i = 0
        while n > 0:
            for _ in range(k - 1):
                pre = i
                i = nxt[i]
            nxt[pre] = nxt[i]
            i = nxt[i]
            n -= 1
        
        return i + 1
