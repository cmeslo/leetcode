# 1004. Max Consecutive Ones III

## Solution: Sliding Window

```cpp
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;

    for (int i = 0, j = 0; j < n; ++j) {
        if (nums[j] == 0) --k;
        while (k < 0) {
            if (nums[i++] == 0) ++k;
        }
        res = max(res, j - i + 1);
    }

    return res;
}
```

or

```cpp
int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0;
    for (; j < nums.size(); ++j) {
        if (nums[j] == 0) --k;
        if (k < 0 && nums[i++] == 0) ++k;
    }
    return j - i;
}
```
