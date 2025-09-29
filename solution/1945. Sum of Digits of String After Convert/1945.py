class Solution:
    def getLucky(self, s: str, k: int) -> int:
        s = "".join(str(ord(x) - ord('a') + 1) for x in s)
        for _ in range(k):
            s = str(sum(int(x) for x in s))
        return int(s)
    
