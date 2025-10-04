class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        target = mean * (m + n) - sum(rolls)
        if n > target: return []
        if n * 6 < target: return []
        
        res = [1] * n
        target -= n
        for i in range(n):
            if target <= 0:
                break
            mn = min(target, 5)
            res[i] += mn
            target -= mn
        return res
    
