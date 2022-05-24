# 461. Hamming Distance

## Solution 1

```cpp
int hammingDistance(int x, int y) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int bitA = (x >> i) & 1;
        int bitB = (y >> i) & 1;
        if (bitA != bitB)
            ++res;
    }
    return res;
}
```

## Solution 2

```cpp
int hammingDistance(int x, int y) {
    int z = x^y, cnt = 0;
    for (int i = 0; i < 32; i++) cnt += (z>>i) & 1;
    return cnt;
}
```

or

```cpp
int hammingDistance(int x, int y) {
    int ans = 0;
    x ^= y;
    while (x) {
        ++ans;
        x &= x - 1;
    }
    return ans;
}
```
