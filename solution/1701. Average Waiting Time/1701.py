class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        total = t = 0
        for arrival, duration in customers:
            t = max(t, arrival) + duration
            total += t - arrival
        return total / len(customers)
    
