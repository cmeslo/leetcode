# 560. Subarray Sum Equals K

## Solution 1: Brute force

```cpp
int subarraySum(vector<int>& nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j) {
            sum += nums[j];
            if (sum == k) ++res;
        }
    }
    return res;
}
```

## Solution 2: Hash map

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m{{0, 1}};
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        ans += m[sum - k];
        ++m[sum];
    }
    return ans;
}
```
