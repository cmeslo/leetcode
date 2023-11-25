class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res, sum = 0, 0
        for x in gain:
            sum += x
            res = max(res, sum)
        return res
