class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        ab = reduce(lambda a, b: a ^ b, nums)
        
        last_bit = ab & (-ab)
        
        res = [0, 0]
        for x in nums:
            if x & last_bit:
                res[0] ^= x
            else:
                res[1] ^= x
        return res
    
