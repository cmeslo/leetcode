# 650. 2 Keys Keyboard

## Solution 1: DFS

```cpp
int minSteps(int n) {
    if (n <= 1) return 0;
    for (int x = n / 2; x >= 2; --x) {
        if (n % x == 0)
            return minSteps(x) + n/x;
    }
    return n;
}
```

or

```cpp
int minSteps(int n) {
    if (n <= 1) return 0;
    for (int x = 2; x < n; ++x) {
        if (n % x == 0)
            return minSteps(n / x) + x;
    }
    return n;
}
```
