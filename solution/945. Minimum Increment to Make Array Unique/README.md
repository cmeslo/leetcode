# 945. Minimum Increment to Make Array Unique

## Solution: Greedy

```cpp
int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int res = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] >= nums[i]) {
            res += nums[i - 1] + 1 - nums[i];
            nums[i] = nums[i - 1] + 1;
        }
    }
    return res;
}
```

or

```cpp
int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int res = 0, need = 0;
    for (int x : nums) {
        res += max(need - x, 0);
        need = max(need, x) + 1;
    }
    return res;
}
```
