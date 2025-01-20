class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        diff = [(num ^ k) - num for num in nums]
        diff.sort(reverse=True)

        max_diff = 0
        for i in range(0, len(nums) - 1, 2):
            d = diff[i] + diff[i + 1]
            if d <= 0:
                break
            max_diff += d

        return max_diff + sum(nums)
    
