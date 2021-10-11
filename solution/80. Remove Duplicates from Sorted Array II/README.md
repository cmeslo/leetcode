# 80. Remove Duplicates from Sorted Array II

## Solution: Two pointers

```cpp
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (j > 1 && nums[i - 2] == nums[j]) continue;
        nums[i++] = nums[j];
    }

    return i;
}
```

or

```cpp
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 1;

    int i = 1;
    for (int j = 2; j < n; ++j) {
        if (nums[i] == nums[j] && nums[i] == nums[i-1]) continue;
        swap(nums[++i], nums[j]);
    }
    return i + 1;
}
```
