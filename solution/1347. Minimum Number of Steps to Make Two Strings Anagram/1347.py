class Solution:
    def minSteps(self, s: str, t: str) -> int:
        f = Counter(s)
        res = 0
        for c in t:
            if f[c] > 0:
                f[c] -= 1
            else:
                res += 1
        return res
    
