class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = [1]
        i2 = i3 = i5 = 0
        for _ in range(n):
            next2 = res[i2] * 2
            next3 = res[i3] * 3
            next5 = res[i5] * 5
            nxt = min(next2, next3, next5)
            res.append(nxt)
            if nxt == next2:
                i2 += 1
            if nxt == next3:
                i3 += 1
            if nxt == next5:
                i5 += 1
        return res[n - 1]
    
