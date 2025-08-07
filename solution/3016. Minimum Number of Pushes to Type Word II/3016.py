class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = sorted(Counter(word).values(), reverse=True)
        res = 0
        for i, freq in enumerate(cnt):
            res += (i // 8 + 1) * freq
        return res
    
