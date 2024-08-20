class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        f = Counter(nums)
        mx = max(f.values())
        return sum(filter(lambda x: x == mx, f.values()))
    
