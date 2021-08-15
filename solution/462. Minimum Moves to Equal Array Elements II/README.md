# 462. Minimum Moves to Equal Array Elements II

## Solution 1: prefixsum

用 prefixsum 求所有元素變成一樣時所需要的步數

```cpp
int minMoves2(vector<int>& nums) {
    sort(begin(nums), end(nums));

    int n = nums.size();
    vector<long> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + nums[i];

    long ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        long moves = 0;
        long left = (i == 0 ? 0 : prefix[i - 1]);
        long right = (i == n - 1 ? 0 : prefix[n - 1] - prefix[i]);
        moves += (i == 0 ? 0 : (long) i * nums[i]) - left;
        moves += right - (i == n - 1 ? 0 : (long) (n - i - 1) * nums[i]);
        ans = min(ans, moves);
    }
    return ans;
}
```

## Solution 2: median

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
