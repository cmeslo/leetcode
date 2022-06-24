# 790. Domino and Tromino Tiling

## Solution: DP

### Explain

```
case A:
x x x x x     x x x x A      x x x A A      x x x x A      x x x A A
x x x x x  =  x x x x A  or  x x x B B  or  x x x A A  or  x x x x A

dp[i][0] = dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]


case B:
x x x x x     x x x A A      x x x A A  
x x x x    =  x x x A    or  x x x x  

dp[i][1] = dp[i-2][0] + dp[i-1][2]


case C:
x x x x       x x x A        x x x x  
x x x x x  =  x x x A A  or  x x x A A

dp[i][2] = dp[i-2][0] + dp[i-1][1]
```

### Code

```cpp
int numTilings(int n) {
    const int M = 1e9 + 7;
    long preA = 1;
    long A = 1, B = 0, C = 0;
    for (int i = 2; i <= n; ++i) {
        long a = (A + preA + B + C) % M;
        long b = (preA + C) % M;
        long c = (preA + B) % M;
        preA = A;
        A = a, B = b, C = c;
    }
    return A;
}
```
