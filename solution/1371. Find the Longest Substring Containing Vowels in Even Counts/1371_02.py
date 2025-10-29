class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        seen = {0: -1}
        res = state = 0
        for i, c in enumerate(s):
            j = 'aeiou'.find(c)
            if j != -1:
                state ^= 1 << j
            seen.setdefault(state, i)
            res = max(res, i - seen[state])
        return res
    
