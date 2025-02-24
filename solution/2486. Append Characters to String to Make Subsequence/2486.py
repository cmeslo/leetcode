class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        j = 0
        for i in range(len(s)):
            if s[i] == t[j]:
                j += 1
                if j == len(t):
                    break
        return len(t) - j
    
