class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        res, indices = -1, {}
        for i, c in enumerate(s):
            res = max(res, i - indices.setdefault(c, i + 1))
        return res
    
