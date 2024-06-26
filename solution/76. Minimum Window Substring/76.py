class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        
        need = defaultdict(int)
        for c in t:
            need[c] += 1
        
        start, size = 0, m + 1
        i, cnt = 0, 0
        for j in range(m):
            if need[s[j]] > 0:
                cnt += 1
            need[s[j]] -= 1
            
            while cnt == n:
                if j - i + 1 < size:
                    start = i
                    size = j - i + 1
                need[s[i]] += 1
                if need[s[i]] > 0:
                    cnt -= 1
                i += 1
        
        return "" if size == m + 1 else s[start:start+size]
