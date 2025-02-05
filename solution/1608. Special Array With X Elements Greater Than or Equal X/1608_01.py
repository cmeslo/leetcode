class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        n = len(nums)
        for i in range(n):
            if nums[i] < i + 1:
                break
            if i + 1 == n or nums[i + 1] < i + 1:
                return i + 1
        return -1
