class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        res = 0
        mn, mx = arrays[0][0], arrays[0][-1]
        for i in range(1, len(arrays)):
            res = max(res, arrays[i][-1] - mn)
            res = max(res, mx - arrays[i][0])
            mn = min(mn, arrays[i][0])
            mx = max(mx, arrays[i][-1])
        return res
    
