class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        m = defaultdict(list)
        m[0].append(-1)
        res = 0
        prefix = 0
        for i in range(len(arr)):
            prefix ^= arr[i]
            for idx in m[prefix]:
                res += i - idx - 1
            m[prefix].append(i)
        return res;
    
