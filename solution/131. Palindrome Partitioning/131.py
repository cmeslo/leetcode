class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s: return [[]]
        res = []
        for i in range(1, len(s) + 1):
            if s[:i] == s[:i][::-1]:
                for suf in self.partition(s[i:]):
                    res.append([s[:i]] + suf)
        return res
    
