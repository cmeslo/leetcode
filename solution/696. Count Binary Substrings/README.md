# 696. Count Binary Substrings

## Solution 1 (696_01.cpp)

zeros 是統計在 i 以及之前，連續出現 0 的個數

ones 是統計在 i 以及之前，連續出現 1 的個數

然後，當出現 0 時，看看目前 ones 的數目是否配匹得上 zeros 的數目

同樣，當出現 1 時，看看目前 zeros 的數目是否配匹得上 ones 的數目

```cpp
int countBinarySubstrings(string s) {
    if (s.empty()) return 1;

    int n = s.length();
    int zeros = 0, ones = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            s[i] == '0' ? ++zeros : ++ones;
        } else {
            if (s[i] == '0') {
                zeros = s[i - 1] == '0' ? zeros + 1 : 1;
                if (ones >= zeros) ++ans;
            } else {
                ones = s[i - 1] == '1' ? ones + 1 : 1;
                if (zeros >= ones) ++ans;
            }
        }
    }

    return ans;
}
```

## Solution 2 (696_02.cpp)

### 解釋

```
[0 0 0 0] [1 1 1] 0
   pre      cur   i
```

```cpp
int countBinarySubstrings(string s) {
    int ans = 0, pre = 0, cur = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i])
            ++cur;
        else {
            ans += min(pre, cur);
            pre = cur;
            cur = 1;
        }
    }
    return ans + min(pre, cur);
}
```
