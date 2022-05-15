# 1413. Minimum Value to Get Positive Step by Step Sum

## Solution 1: 倒放 / 回帶

```cpp
int minStartValue(vector<int>& nums) {
    int res = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        res = max(1, res - nums[i]);
    }
    return res;
}
```
