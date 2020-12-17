# 81. Search in Rotated Sorted Array II

## 81_01.cpp

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

## 81_02.cpp

按照數組性質做 binary search，

time complexity: O(logn)

the worst case: O(n)

```cpp
bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target) return true;

        // 前半段有序：
        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        // 後半段有序：
        } else if (nums[mid] < nums[r]) {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        // 不知道 前半 還是 後半 有序，一點點縮小範圍：
        } else {
            if (nums[l] == nums[mid])
                ++l;
            else
                --r;
        }
    }

    return false;
}
```
