class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        hp = list(collections.Counter(arr).values())
        heapq.heapify(hp)
        while k > 0:
            if k < hp[0]:
                break
            k -= heapq.heappop(hp)
        return len(hp)
    
