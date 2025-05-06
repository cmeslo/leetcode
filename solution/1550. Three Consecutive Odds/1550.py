class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        odds = 0
        for x in arr:
            odds = odds + 1 if x % 2 == 1 else 0
            if odds == 3:
                return True
        return False
    
