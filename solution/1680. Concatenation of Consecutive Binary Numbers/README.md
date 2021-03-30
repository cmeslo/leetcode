# 1680. Concatenation of Consecutive Binary Numbers

## 解釋

對於每一個 i (1至n)，skip leading zeros 之後，就是它的實際長度 len，

把 ans 左移 len 位、也就是留 len 個位置，之後再加上 i，

不斷重複這個步驟。

### 寫法一：自己循環去數有效長度

```cpp
int concatenatedBinary(int n) {
    const int k = 1e9 + 7;

    long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        int len = 31;
        while (len && ((num >> len) & 1) != 1) --len; // skip zeros
        ans = (ans << (len + 1)) + num;
        ans %= k;
    }
    return ans;
}
```

簡化一點：

```cpp
int concatenatedBinary(int n) {
    const int k = 1e9 + 7;

    long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int len = 0;
        for (int j = i; j; j >>= 1, ++len);
        ans = ((ans << len) % k + i) % k;
    }
    return ans;
}
```

### 寫法二：用 build in function - count leading zeros

```cpp
int concatenatedBinary(int n) {
    const int k = 1e9 + 7;

    long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int len = 32 - __builtin_clz(i);
        ans = ((ans << len) % k + i) % k;
    }
    return ans;
}
```

### 寫法三：找規律

發現每當去到 <strong>2的n次方</strong> 時，有效長度才會加 1

```cpp
int concatenatedBinary(int n) {
    const int k = 1e9 + 7;

    long ans = 0;
    for (int i = 1, len = 0; i <= n; ++i) {
        if ((i & (i - 1)) == 0) ++len;
        ans = ((ans << len) % k + i) % k;
    }
    return ans;
}
```
