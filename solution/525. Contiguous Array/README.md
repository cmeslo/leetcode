# 525. Contiguous Array

```cpp
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> m;
    int res = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i] == 1 ? 1 : -1;
        if (sum == 0)
            res = i + 1;
        else if (m.count(sum))
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}
```
