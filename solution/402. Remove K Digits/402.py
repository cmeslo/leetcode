class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        res = []
        
        for c in num:
            while res and res[-1] > c and k:
                res.pop()
                k -= 1
            if res or c != '0':
                res.append(c)
        
        while res and k:
            res.pop()
            k -= 1
        
        return ''.join(res) if res else '0'
    
