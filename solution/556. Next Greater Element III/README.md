# 556. Next Greater Element III

## 解釋:

1. 從後往前，找到第一個下降的數字，索引 i
2. 從後往前，找第一個比s[i]大的數字，索引 j
3. 找到 i 和 j 後交換，然後 sort 或 reverse 在 i 之後的數字

例子：
```
12
|^---------j
^----------i

47651
|  ^-------j
^----------i

12443322
 |   ^-----j
 ^---------i
```

## Code:
```cpp
int nextGreaterElement(int n) {
    string s = to_string(n);

    // 1. 從後往前，找到第一個下降的數字，索引 i
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1]) --i;
    if (i == -1) return -1;

    // 2. 從後往前，找第一個比s[i]大的數字，索引 j
    int j = s.size() - 1;
    while (j > i && s[i] >= s[j]) --j; // 為什麼要用 >=，要留意上面第三個例子

    // 3. 找到 i 和 j 後交換，然後 sort 或 reverse 在 i 之後的數字
    swap(s[i], s[j]);
    reverse(begin(s) + i + 1, end(s)); // sort(begin(s) + i + 1, end(s));

    long ans = stol(s);
    return ans > INT_MAX ? -1 : ans;
}
```
