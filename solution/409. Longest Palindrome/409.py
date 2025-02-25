class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = [0] * 128
        
        for c in s:
            freq[ord(c)] += 1
            
        res = 0
        mid = 0
        for f in freq:
            if f % 2:
                mid = 1
                res += f - 1
            else:
                res += f
        return res + mid
    
