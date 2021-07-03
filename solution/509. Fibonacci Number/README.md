# 509. Fibonacci Number

## Solution: DP

```cpp
dp[i] = dp[i - 1] + dp[i - 2]
```

### Code

```cpp
int fib(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, c = 1;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
```
