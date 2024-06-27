class Solution:
    def firstUniqChar(self, s: str) -> int:
        f = defaultdict(int)
        for c in s:
            f[c] += 1
        for i in range(len(s)):
            if f[s[i]] == 1:
                return i
        return -1
    
