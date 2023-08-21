# 2405. Optimal Partition of String

## Solution

### 寫法一：

```cpp
// Runtime 224 ms, Beats 38.83%

int partitionString(string s) {
    unordered_set<char> w;
    int res = 1;
    for (char& c : s) {
        if (w.count(c)) {
            res++;
            w.clear();
        }
        w.insert(c);
    }
    return res;
}
```

### 寫法二（推薦）：


```cpp
// Runtime 17 ms, Beats 95.11%

int partitionString(string s) {
    int cnt = 0, res = 1;
    for (char& c : s) {
        int i = c - 'a';
        if ((cnt & (1 << i)) != 0) {
            res++;
            cnt = 0;
        }
        cnt |= (1 << i);
    }
    return res;
}
```
