# 231. Power of Two

```cpp
bool isPowerOfTwo(int n) {
    int cnt = 0;
    while (n) {
        cnt += (n & 1);
        if (cnt > 1) return false;
        n >>= 1;
    }
    return cnt == 1;
}
```

or

```cpp
bool isPowerOfTwo(int n) {
    return (n > 0) && (n & (n - 1)) == 0;
}
```
