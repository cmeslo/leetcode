class Solution:
    def combinationSum2(self, A: List[int], target: int) -> List[List[int]]:
        A.sort()
        res = []
        
        def dfs(target, start, cur, res):
            if target < 0:
                return
            if target == 0:
                res.append(cur)
                return
            
            for i in range(start, len(A)):
                if start < i and A[i - 1] == A[i]:
                    continue
                dfs(target - A[i], i + 1, cur + [A[i]], res)
        
        dfs(target, 0, [], res)
        return res
    
