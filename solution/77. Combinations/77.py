class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def dfs(start, cur):
            if len(cur) == k:
                res.append(cur)
                return
            for i in range(start, n + 1):
                dfs(i + 1, cur + [i])
        
        dfs(1, [])
        return res
