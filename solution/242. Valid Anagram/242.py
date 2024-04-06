class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        
        cnt = [0] * 26;
        
        for c in s:
            cnt[ord(c) - ord('a')] += 1
            
        for c in t:
            cnt[ord(c) - ord('a')] -= 1
            if cnt[ord(c) - ord('a')] < 0:
                return False
            
        return True
