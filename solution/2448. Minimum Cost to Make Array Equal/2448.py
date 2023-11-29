class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        n = len(nums)

        A = sorted(zip(nums, cost), key=lambda x: x[0])
        nums, cost = zip(*A)

        costSum = list(accumulate(cost))
        
        leftCost, rightCost = [0] * n, [0] * n
        for i in range(1, n):
            leftCost[i] = leftCost[i-1] + (nums[i] - nums[i-1]) * costSum[i-1]
        for i in range(n-2, -1, -1):
            rightCost[i] = rightCost[i+1] + (nums[i+1] - nums[i]) * (costSum[n-1] - costSum[i])
        
        res = float('inf')
        for i in range(n):
            res = min(res, leftCost[i] + rightCost[i])
        return res
