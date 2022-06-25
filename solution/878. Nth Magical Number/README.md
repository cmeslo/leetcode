# 878. Nth Magical Number

## Solution: Binary search + math

```cpp
int nthMagicalNumber(int n, int a, int b) {
    int mod = 1e9 + 7;
    long lcm_ab = lcm(a, b);
    long l = 1, r = 1e15;
    while (l < r) {
        long m = l + (r - l) / 2;
        if (m / a + m / b - m / lcm_ab < n)
            l = m + 1;
        else
            r = m;
    }
    return l % mod;
}
```

## reference
[Inclusion–exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle)

