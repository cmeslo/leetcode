class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        A = sorted([x for x, y in points])
        return max([b - a for a, b in zip(A, A[1:])] + [0])
    
