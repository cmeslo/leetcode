class Solution:
    def customSortString(self, order: str, s: str) -> str:
        m = defaultdict(int)
        for c in s:
            m[c] += 1
            
        res = ''
        for c in order:
            res += c * m[c]
            m[c] = 0
        
        for c, count in m.items():
            res += c * count
        
        return res
    
