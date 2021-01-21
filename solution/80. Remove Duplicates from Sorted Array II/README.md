# 80. Remove Duplicates from Sorted Array II

## Two pointers

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
