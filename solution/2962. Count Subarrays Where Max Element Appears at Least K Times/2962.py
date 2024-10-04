class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mx = max(nums)
        res = i = mx_cnt = 0
        
        for j in range(n):
            if nums[j] == mx:
                mx_cnt += 1
                while mx_cnt >= k:
                    res += n - j
                    if nums[i] == mx:
                        mx_cnt -= 1
                    i += 1
        
        return res
    
