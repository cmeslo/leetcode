class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        res = 0
        for i in range(k):
            if happiness[i] <= i:
                break
            res += happiness[i] - i
        return res
    
