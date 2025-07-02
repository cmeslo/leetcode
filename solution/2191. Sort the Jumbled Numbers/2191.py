class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        
        def hash(num):
            x = ''.join(str(mapping[int(digit)]) for digit in str(num))
            return int(x)
        
        A = [(hash(nums[i]), i) for i in range(len(nums))]
        A.sort()
        return [nums[i] for _, i in A]
    
