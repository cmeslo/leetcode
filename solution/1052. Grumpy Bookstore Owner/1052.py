class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        presum = add_satisfied = max_add_satisfied = 0
        for i in range(len(customers)):
            presum += customers[i] * (1 - grumpy[i])
            add_satisfied += customers[i] * grumpy[i]
            if i >= minutes:
                add_satisfied -= customers[i - minutes] * grumpy[i - minutes]
            max_add_satisfied = max(max_add_satisfied, add_satisfied)
        return presum + max_add_satisfied
    
