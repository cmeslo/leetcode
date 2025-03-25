class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        heap = []
        A = sorted(zip(capital, profits), key=lambda p: p[0])
        i = 0
        for _ in range(k):
            while i < len(A) and A[i][0] <= w:
                heapq.heappush(heap, -A[i][1])
                i += 1
            if not heap:
                break
            w -= heapq.heappop(heap)
        return w
    
