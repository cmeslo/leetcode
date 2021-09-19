# 795. Number of Subarrays with Bounded Maximum

## Solution 1: Two pass（容易理解）

```小於等於 right 的集合``` 減去 ```小於 left 的集合```

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
    
private:
    int count(vector<int>& nums, int N) {
        int res = 0, cur = 0;
        for (int x : nums) {
            if (x <= N)
                ++cur;
            else
                cur = 0;
            res += cur;
        }
        return res;
    }
};
```
