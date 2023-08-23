# 2439. Minimize Maximum of Array

## Solution: Binary search

### 寫法一

```cpp
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (checkOK(nums, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private:
    bool checkOK(vector<int>& nums, int mx) {
        long carry = 0;
        for (int i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] + carry > mx) {
                carry = nums[i] + carry - mx;
            } else {
                carry = 0;
            }
        }
        return nums[0] + carry <= mx;
    }
};
```

### 寫法二

```cpp
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (checkOK(nums, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private:
    bool checkOK(vector<int>& nums, int limit) {
        long cap = 0;
        for (int x : nums) {
            cap -= x - limit;
            if (cap < 0)
                return false;
        }
        return true;
    }
};
```
