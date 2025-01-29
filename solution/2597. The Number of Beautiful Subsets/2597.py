class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count = Counter()
        res = 0
        
        nums.sort()
        
        def dfs(i):
            nonlocal res
            
            if i == n:
                res += 1
                return
            
            dfs(i + 1)
            
            pre = nums[i] - k
            if pre <= 0 or count[pre] == 0:
                count[nums[i]] += 1
                dfs(i + 1)
                count[nums[i]] -= 1
        
        dfs(0)
        return res - 1
    
