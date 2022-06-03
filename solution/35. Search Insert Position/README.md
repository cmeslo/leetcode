# 35. Search Insert Position

## Solution 1

time: ```O(N)```

```cpp
int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) return i;
    }
    return nums.size();
}
```

## Solution 2: Binary search

time: ```O(logN)```

```cpp
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}
```
