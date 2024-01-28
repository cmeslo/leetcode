class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        seen = [False for _ in range(n)]
        
        def dfs(nums, cur):
            if len(cur) == n:
                res.append(cur);
                return
            
            for i in range(n):
                if seen[i]:
                    continue
                seen[i] = True
                dfs(nums, cur + [nums[i]])
                seen[i] = False
        
        dfs(nums, [])
        return res
