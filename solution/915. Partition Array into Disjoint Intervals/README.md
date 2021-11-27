# 915. Partition Array into Disjoint Intervals

## Solution 1

```cpp
int partitionDisjoint(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    int mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        left[i] = mx = max(mx, nums[i]);
        right[n - i - 1] = mn = min(mn, nums[n - i - 1]);
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (left[i] <= right[i + 1])
            return i + 1;
    }
    return -1;
}
```
