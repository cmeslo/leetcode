# 1480. Running Sum of 1d Array

```cpp
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];
    return nums;
}
```

or

```cpp
vector<int> runningSum(vector<int>& nums) {
    partial_sum(begin(nums), end(nums), begin(nums));
    return nums;
}
```
