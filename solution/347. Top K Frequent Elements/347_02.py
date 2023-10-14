class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = collections.Counter(nums)
        h = []
        for num in counts.keys():
            heapq.heappush(h, (counts[num], num))
            if len(h) > k: heapq.heappop(h)
        return [heapq.heappop(h)[1] for i in range(k)]
