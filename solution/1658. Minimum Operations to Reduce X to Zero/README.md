# 1658. Minimum Operations to Reduce X to Zero

## Solution 1: prefix sum + hashmap (1658_01.cpp)
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

## Solution 2 : sliding window (1658_02.cpp)

```cpp
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int target = -x;
    for (int num : nums)
        target += num;

    if (target < 0) return -1;
    if (target == 0) return n;

    int len = INT_MIN;
    int sum = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum >= target) {
            if (sum == target)
                len = max(len, r - l + 1);
            sum -= nums[l++];
        }
    }

    return len == INT_MIN ? -1 : n - len;
}
```

or

```cpp
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int target = accumulate(begin(nums), end(nums), -x);

    if (target < 0) return -1;
    if (target == 0) return n;

    int len = INT_MIN;
    int sum = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j];

        while (sum > target) // 因為target > 0，所以必定有解，i 不會超過 j，可以不用檢查 i <= j
            sum -= nums[i++];

        if (sum == target)
            len = max(len, j - i + 1);
    }

    return len == INT_MIN ? -1 : n - len;
}
```
