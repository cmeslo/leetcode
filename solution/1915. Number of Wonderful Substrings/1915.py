class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        cnt = [0] * (1 << 10)
        cnt[0] = 1
        res = state = 0
        
        for c in word:
            state ^= (1 << (ord(c) - ord('a')))
            res += cnt[state]
            res += sum(cnt[state ^ (1 << i)] for i in range(10))
            cnt[state] += 1
        return res
    
