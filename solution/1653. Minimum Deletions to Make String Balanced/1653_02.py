class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        s = '#' + s
        dpi = b_count = 0
        for i in range(1, n + 1):
            if s[i] == 'a':
                dpi = min(dpi + 1, b_count)
            else:
                b_count += 1
        return dpi
    
