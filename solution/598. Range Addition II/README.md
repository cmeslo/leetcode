# 598. Range Addition II

被塗鴉的、維持最大值的範圍，只會越來越小。

```cpp
int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (auto& op : ops) {
        m = min(m, op[0]);
        n = min(n, op[1]);
    }
    return m * n;
}
```
