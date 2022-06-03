# 53. Maximum Subarray

## Solution 1: Kadane's algorithm

```cpp
int maxSubArray(vector<int>& nums) {
    int ans, sum;
    ans = sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max(sum + nums[i], nums[i]);
        ans = max(ans, sum);
    }

    return ans;
}
```


## Solution 2

```
[x x x] [x x x x] x x x
     ^         ^
     min_sum   sum
```

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = 0, sum = 0, res = nums[0];
        for (int x : nums) {
            sum += x;
            res = max(res, sum - mn);
            mn = min(mn, sum);
        }
        return res;
    }
};
```
