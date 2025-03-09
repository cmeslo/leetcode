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

or

```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum = (sum + nums[i]) % k;
        if (m.count(sum)) {
            if (i - m[sum] > 1)
                return true;
        } else {
            m[sum] = i;
        }
    }
    return false;
}


// x x x [x x x x] x x
//     j        i

// (presum[i] - presum[j]) % k = 0

// presum[i] - presum[j] = n * k
// presum[j] = presum[i] - n * k
// presum[j] % k = presum[i] % k

// 23 2  4  6  6
// 23 25 29 35 41
```
