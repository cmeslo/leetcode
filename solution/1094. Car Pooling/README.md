# 1094. Car Pooling

## Solution - Diff Array

```cpp
// Your runtime beats 99.70 % of cpp submissions.
// Your memory usage beats 53.11 % of cpp submissions.

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001);
    for (auto& t : trips) {
        diff[t[1]] -= t[0];
        diff[t[2]] += t[0];
    }
    for (int x : diff) {
        capacity += x;
        if (capacity < 0) return false;
    }
    return true;
}
```
