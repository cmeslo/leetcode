class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        cnt = [0] * n
        res = 0
        for r in roads:
            cnt[r[0]] += 1
            cnt[r[1]] += 1
        
        cnt.sort()
        
        for i in range(n):
            res += cnt[i] * (i + 1)
        return res
    
