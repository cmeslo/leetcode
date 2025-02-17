class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        freq = defaultdict(int)
        total = defaultdict(int)
        freq[0] = 1
        res = 0
        x = 0
        for i in range(len(arr)):
            x ^= arr[i]
            res += freq[x] * i - total[x]
            freq[x] += 1
            total[x] += i + 1
        return res
    
