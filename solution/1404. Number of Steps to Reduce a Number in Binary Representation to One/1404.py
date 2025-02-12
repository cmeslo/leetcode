class Solution:
    def numSteps(self, s: str) -> int:
        res, carry = 0, 0
        for i in range(len(s) - 1, 0, -1):
            if int(s[i]) + carry == 1:
                carry = 1
                res += 1
            res += 1
        return res + carry
    
