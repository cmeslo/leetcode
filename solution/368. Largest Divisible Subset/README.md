# 368. Largest Divisible Subset

## Solution 1: Recursion + memo (368_01.cpp)
最開始用 recursive 方法做會TLE，加上memo優化後Accepted，但時間複雜度高。

## Solution 2: DP (368_02.cpp)

DP 的解法，學習了 https://www.youtube.com/watch?v=Wv6DlL0Sawg 的方法

```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int max_len = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && (1+dp[j] > dp[i])) {
                    dp[i] = 1 + dp[j];
                    if (dp[i] > max_len) max_len = dp[i];
                }
            }
        }
        
        vector<int> res;
        int prev = -1;
        for (int i = n-1; i >= 0; --i) {
            if (dp[i]==max_len && (prev%nums[i]==0 || prev==-1)) {
                res.push_back(nums[i]);
                max_len--;
                prev = nums[i];
            }
        }
        return res;
    }
};
```

## Solution 3: DP (368_03.cpp)

不同的找答案方法。

```cpp
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int max_len = 0;
    int index = 0;
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            index = i;
            max_len = dp[i];
        }
    }

    vector<int> res;
    while (index != -1) {
        res.push_back(nums[index]);
        index = prev[index];
    }
    return res;
}
```
