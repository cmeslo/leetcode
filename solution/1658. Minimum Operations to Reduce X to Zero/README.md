# 1658. Minimum Operations to Reduce X to Zero

```cpp
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int target = -x;
    for (int num : nums)
        target += num;

    if (target == 0) return n;

    int sub = INT_MIN; // maximum sub array size
    unordered_map<int, int> left; // prefix_sum -> index
    left[0] = -1;
    for (int i = 0, sum = 0; i < n; ++i) {
        sum += nums[i];
        if (left.count(sum - target))
            sub = max(sub, i - left[sum - target]);
        left[sum] = i;
    }

    return sub == INT_MIN ? -1 : n - sub;
}
```
