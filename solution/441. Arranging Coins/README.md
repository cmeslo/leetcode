# 441. Arranging Coins

## 441_01.cpp

Time complexity: O(n)

```cpp
int arrangeCoins(int n) {
    int coin = 0;

    while (n-coin > coin) n -= coin++;

    return coin;
}
```

## 441_02.cpp

Time complexity: O(logn)

```cpp
int arrangeCoins(int n) {
    if (n <= 1) return n;
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high-low)/2;
        long total = (long) mid*(1+mid)/2;
        if (total == n) return mid;
        if (total < n) low = mid + 1;
        else high = mid;
    }

    return low - 1;
}
```

## 441_03.cpp

Time complexity: O(1)

```cpp
int arrangeCoins(int n) {
    // x(1 + x)/2 = n
    // x^2 + x - 2n = 0
    // x = (-1 + sqrt(1 + 8*n))/2
    return (int) (-1 + sqrt(1 + 8*(long)n))/2;
}
```
