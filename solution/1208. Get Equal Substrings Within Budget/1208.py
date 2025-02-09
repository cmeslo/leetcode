class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        j = 0
        for i in range(len(s)):
            maxCost -= abs(ord(s[i]) - ord(t[i]))
            if maxCost < 0:
                maxCost += abs(ord(s[j]) - ord(t[j]))
                j += 1
        return i - j + 1 # python 的 for 循環只會去到 n-1
        
