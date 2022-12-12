# 1461. Check If a String Contains All Binary Codes of Size K

## 解釋

遍歷 string s，不斷把連續的、長度為 k 的子字符串插入到 set 裡，最後看看 set 的大小是不是等於 2^k。

## Code

```cpp
bool hasAllCodes(string s, int k) {
    unordered_set<string> codes;

    for (int i = 0; i + k - 1 < s.size(); ++i)
        codes.insert(s.substr(i, k));

    return codes.size() == (1 << k);
}
```

還可以做一點小優化，預先判斷有沒有可能構成 2^k 種組合：

```cpp
if ((n - k + 1) * k < (1 << k)) return false;
```

## Code

```cpp
bool hasAllCodes(string s, int k) {
    int n = s.size();
    if ((n - k + 1) * k < (1 << k)) return false;

    unordered_set<string> codes;
    for (int i = 0; i + k - 1 < n; ++i)
        codes.insert(s.substr(i, k));

    return codes.size() == (1 << k);
}
```

or

```cpp
bool hasAllCodes(string s, int k) {
    int n = s.size();
    if ((n - k + 1) * k < (1 << k)) return false;

    unordered_set<int> codes;
    for (int i = 0; i + k <= n; ++i) {
        int x = 0;
        for (int j = 0; j < k; ++j)
            if (s[i + j] == '1')
                x |= (1 << j);
        codes.insert(x);
    }
    return codes.size() == (1 << k);
}
```
