# 81. Search in Rotated Sorted Array II

## Solution 1: Recover (81_01.cpp)

先把數組復原，再 binary search.

time complexity: O(n + logn)

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        rotate(nums);

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        
        return false;
    }
    
private:
    void rotate(vector<int>& nums) {
        int i;
        for (i = 1; i < nums.size(); ++i)
            if (nums[i - 1] > nums[i]) break;
        
        if (i == nums.size()) return;
        
        reverse(begin(nums), begin(nums) + i);
        reverse(begin(nums) + i, end(nums));
        reverse(begin(nums), end(nums));
    }
};
```

## Solution 2: Binary search (81_02.cpp)

按照數組性質做 binary search，

average time complexity: O(logn)

the worst case: O(n)

```cpp
bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) return true;

        // 前半段有序：
        if (nums[l] < nums[m]) {
            if (nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        // 後半段有序：
        } else if (nums[m] < nums[r]) {
            if (nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        // 不知道 前半 還是 後半 有序，一點點縮小範圍：
        } else {
            if (nums[l] == nums[m])
                ++l;
            else
                --r;
        }
    }

    return false;
}
```
