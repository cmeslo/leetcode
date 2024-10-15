class Solution:
    def maxDepth(self, s: str) -> int:
        res = left = 0
        for c in s:
            if c == '(':
                left += 1
                res = max(res, left)
            elif c == ')':
                left -= 1
        return res
    
