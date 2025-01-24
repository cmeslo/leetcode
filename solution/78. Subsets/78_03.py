class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for state in range(1 << n):
            cur = []
            for i in range(n):
                if (state >> i) & 1:
                    cur.append(nums[i])
            res.append(cur)
        return res
    
