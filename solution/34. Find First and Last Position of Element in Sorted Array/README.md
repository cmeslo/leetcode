# 34. Find First and Last Position of Element in Sorted Array

## 寫法一：

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int first = lower_bound(begin(nums), end(nums), target) - begin(nums);
    if (first == nums.size() || nums[first] != target)
        return {-1, -1};
    int last = upper_bound(begin(nums), end(nums), target) - begin(nums);
    return {first, last - 1};
}
```

## 寫法二：

自己實現 lower_bound 和 upper_bound 方法

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = -1, last = -1;
    int left = 0, right = n, mid;

    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (left == n || nums[left] != target) return {-1, -1};
    first = left;

    left = 0, right = n;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    last = left - 1;

    return {first, last};
}
```
