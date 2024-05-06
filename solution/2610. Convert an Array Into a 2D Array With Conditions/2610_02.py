class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        d = defaultdict(lambda: 0)
        res = []
        for x in nums:
            if d[x] >= len(res):
                res.append([])
            res[d[x]].append(x)
            d[x] += 1
        return res
    
