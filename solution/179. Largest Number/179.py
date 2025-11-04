class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cmp(a, b):
            if a + b > b + a:
                return -1
            elif a == b:
                return 0
            return 1
        
        nums = [str(x) for x in nums]
        
        nums.sort(key = cmp_to_key(cmp))
        
        return ''.join(nums).lstrip('0') or '0'
    
