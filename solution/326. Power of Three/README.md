# 326. Power of Three

## Solution 1: Brute force
```cpp
bool isPowerOfThree(int n) {
    if (n == 0) return 0;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}
```

## Solution 2: 換底公式

```cpp
bool isPowerOfThree(int n) {
    return n > 0 && (log10(n) / log10(3)) - int(log10(n) / log10(3)) == 0;
}
```

## Solution 3: math

```cpp
bool isPowerOfThree(int n) {
    // 找到 int 範圍內的最大的、3的次方數，通過以下代碼可以找到 19，所以是 3^19 
    // int cnt = 0;
    // while (pow(3, cnt) <= INT_MAX)
    //     ++cnt;
    // cout << cnt - 1 << endl;

    int mx = 1162261467; // pow(3, 19)
    return n > 0 && mx % n == 0;
}
```
