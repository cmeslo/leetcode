class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a, b = 0, int(sqrt(c))
        while a <= b:
            m = a*a + b*b
            if m == c:
                return True
            if m < c:
                a += 1
            else:
                b -= 1
        return False
    
