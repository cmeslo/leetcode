class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m1 = defaultdict(lambda: -1)
        m2 = defaultdict(lambda: -1)
        for i in range(len(s)):
            if m1[s[i]] != m2[t[i]]:
                return False
            m1[s[i]] = i
            m2[t[i]] = i
        return True
    
