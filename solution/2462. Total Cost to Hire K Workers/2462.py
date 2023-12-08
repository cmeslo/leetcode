class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        heap = []
        i, j = -1, n

        while i + 1 < n and i + 1 < candidates:
            i += 1
            heapq.heappush(heap, (costs[i], i))

        while j - 1 > i and j - 1 >= n - candidates:
            j -= 1
            heapq.heappush(heap, (costs[j], j))

        res = 0
        while heap and k > 0:
            cost, idx = heapq.heappop(heap)
            res += cost
            k -= 1

            if i + 1 == j:
                continue

            if idx <= i:
                i += 1
                heapq.heappush(heap, (costs[i], i))
            else:
                j -= 1
                heapq.heappush(heap, (costs[j], j))

        return res
