class Solution:
    def makeGood(self, s: str) -> str:
        res = []
        for c in s:
            if res and res[-1] == c.swapcase():
                res.pop()
            else:
                res.append(c)
        return "".join(res)
    
