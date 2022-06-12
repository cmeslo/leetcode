# 198. House Robber

## Solution 1: DP

```cpp
int rob(vector<int>& nums) {
    int prepre = 0, pre = 0;
    for (int x : nums) {
        int cur = max(prepre + x, pre);
        prepre = pre;
        pre = cur;
    }
    return max(prepre, pre);
}
```
