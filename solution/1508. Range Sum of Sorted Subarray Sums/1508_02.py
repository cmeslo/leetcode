class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        pq = [(nums[i], i) for i in range(n)]
        heapify(pq)
        
        res = 0
        for k in range(1, right + 1):
            val, i = heappop(pq)
            if k >= left:
                res = (res + val) % (10**9 + 7)
            if i + 1 < n:
                heappush(pq, (val + nums[i + 1], i + 1))
        return res
    
