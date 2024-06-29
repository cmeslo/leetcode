class Solution:
    def frequencySort(self, s: str) -> str:
        n = len(s)
        
        f = defaultdict(int)
        for c in s:
            f[c] += 1
        
        bucket = [[] for _ in range(n + 1)]
        for c, cnt in f.items():
            bucket[cnt].append(c)
        
        res = ""
        for i in range(n, 0, -1):
            for c in bucket[i]:
                res += i * c
        return res
    
