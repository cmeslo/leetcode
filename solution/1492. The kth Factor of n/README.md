# 1492. The kth Factor of n

## 1492_01.cpp

可以觀察到，一個數字的因子最多只會去到該數字的一半

```
12
1, 2, 3, 4, 6, 12

25
1, 5, 25
```

所以可以寫出代碼：

```cpp
int kthFactor(int n, int k) {
    int cnt = 0;

    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) ++cnt;
        if (cnt == k) return i;
    }
    if (++cnt == k) return n; 

    return -1;
}
```

寫簡潔一點：

```cpp
int kthFactor(int n, int k) {
    for (int x = 1; x <= n / 2; ++x)
        if (n % x == 0 && --k == 0)
            return x;

    return k == 1 ? n : -1;;
}
```

Time: O(N/2) -> O(N)
