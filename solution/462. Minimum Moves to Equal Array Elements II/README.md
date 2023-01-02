# 462. Minimum Moves to Equal Array Elements II

## Solution 1: Prefix sum

用 prefixsum 求所有元素變成一樣時所需要的步數

```cpp
int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i)
        presum[i] = presum[i - 1] + nums[i - 1];

    long ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        long left = 1L * nums[i - 1] * (i - 1) - presum[i - 1];
        long right = presum[n] - presum[i] - 1L * (n - i) * nums[i - 1];
        ans = min(ans, left + right);
    }
    return ans;
}
```

## Solution 2: Median

```cpp
int minMoves2(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int ans = 0;
    int i = 0, j = nums.size() - 1;
    while (i < j)
        ans += nums[j--] - nums[i++];
    return ans;
}
```

or

```cpp
int minMoves2(vector<int>& nums) {
    int n = nums.size();
    nth_element(begin(nums), begin(nums) + n / 2, end(nums));

    int ans = 0;
    for (int x : nums)
        ans += abs(x - nums[n / 2]);
    return ans;
}
```
