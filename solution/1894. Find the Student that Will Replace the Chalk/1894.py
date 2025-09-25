class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        k %= sum(chalk)
        for i, x in enumerate(chalk):
            k -= x
            if k < 0:
                return i
        return 0
    
