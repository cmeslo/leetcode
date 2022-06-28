# 2195. Append K Integers With Minimal Sum

## Solution: Math

```cpp
// Runtime: 132 ms, Your runtime beats 100.00 % of cpp submissions.
// Memory Usage: 66.2 MB, Your memory usage beats 75.56 % of cpp submissions.

long long minimalKSum(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long ans = 0;
    int pre = 0;
    for (int x : nums) {
        if (pre == x) continue;
        long cnt = min(x - pre - 1, k);
        k -= cnt;
        ans += cnt * (pre + 1 + pre + cnt) / 2;
        pre = x;
        if (k == 0) break;
    }
    if (k > 0) {
        ans += (long)k * (nums.back() + 1 + nums.back() + k) / 2;
    }
    return ans;
}
```
