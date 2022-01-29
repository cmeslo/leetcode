# 2104. Sum of Subarray Ranges

```cpp
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long res = 0;
    for (int i = 0; i < n; ++i) {
        int mx = nums[i], mn = nums[i];
        for (int j = i; j < n; ++j) {
            mx = max(mx, nums[j]);
            mn = min(mn, nums[j]);
            res += mx - mn;
        }
    }
    return res;
}
```
