class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = [0] * n
        x = 1
        for i in range(n):
            res[i] = x
            if x * 10 <= n:
                x *= 10
            else:
                while x + 1 > n or x % 10 == 9:
                    x //= 10
                x += 1
        return res
    
