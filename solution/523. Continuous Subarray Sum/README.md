# 523. Continuous Subarray Sum

## Solution: Hashmap

```
x x x [x x x] x x
       i   j

sum[i:j] % k = 0

(sum[j] - sum[i-1]) % k = 0;

sum[j] - sum[i-1] = nk;

sum[j] - nk = sum[i-1]

sum[j] % k = sum[i-1] % k
```

```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int x = sum % k;
        if (x == 0 && i > 0) return true;
        if (m.count(x) && i - m[x] >= 2) return true;
        if (!m.count(x)) m[x] = i;
    }
    return false;
}
```
