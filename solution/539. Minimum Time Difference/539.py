class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        T = sorted(int(t[:2]) * 60 + int(t[-2:]) for t in timePoints)
        T.append(T[0] + 1440)
        return min(b - a for a, b in zip(T, T[1:]))
    
