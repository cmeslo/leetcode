# 191. Number of 1 Bits

```n & (n - 1)``` to remove the last 1 bit.

```cpp
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        ++ans;
        n &= n - 1;
    }
    return ans;
}
```
