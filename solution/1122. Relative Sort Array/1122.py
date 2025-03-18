class Solution:
    def relativeSortArray(self, A: List[int], B: List[int]) -> List[int]:
        m = {val: i for i, val in enumerate(B)}
        return sorted(A, key=lambda x: m.get(x, 1000 + x))
    
