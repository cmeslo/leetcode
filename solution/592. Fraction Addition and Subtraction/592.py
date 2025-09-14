class Solution:
    def fractionAddition(self, expression: str) -> str:
        ints = map(int, re.findall('[+-]?\d+', expression))
        A, B = 0, 1
        for a in ints:
            b = next(ints)
            A = A * b + a * B
            B *= b
            g = math.gcd(A, B)
            A //= g
            B //= g
        return '%d/%d' % (A, B)
    
# A/B + a/b = (Ab + aB) / Bb
