class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        m = Counter(arr)
        for x in arr:
            if m[x] == 1:
                k -= 1
                if k == 0:
                    return x
        return ''
    
