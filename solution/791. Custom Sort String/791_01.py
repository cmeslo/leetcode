class Solution:
    def customSortString(self, order: str, s: str) -> str:
        m = defaultdict(int)
        for i in range(len(order)):
            m[order[i]] = i + 1
        
        s = sorted(s, key=lambda c: m[c])
        return ''.join(s)
    
