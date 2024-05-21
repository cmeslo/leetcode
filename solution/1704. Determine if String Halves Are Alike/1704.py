class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        m = len(s) // 2
        vowels = "aeiouAEIOU"
        cnt = 0
        for i in range(m):
            cnt += s[i] in vowels
            cnt -= s[i + m] in vowels
        return cnt == 0
