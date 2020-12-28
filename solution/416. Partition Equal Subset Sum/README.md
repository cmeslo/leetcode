# 416. Partition Equal Subset Sum

## Recursive (416_01.cpp)

Your runtime beats 95.95 % of cpp submissions.

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1) return false;
        
        mem.clear();
        mem.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        
        return subsetSum(nums, 0, sum / 2);
    }
    
private:
    vector<vector<int>> mem;
    
    bool subsetSum(vector<int>& nums, int i, int remain) {
        if (remain == 0) return true;
        if (i >= nums.size() || remain < 0) return false;
        if (mem[i][remain] != -1) return mem[i][remain];
        
        return mem[i][remain] = subsetSum(nums, i + 1, remain - nums[i])
            || subsetSum(nums, i + 1, remain);
    }
};
```

## DP (416_02.cpp)

二維數組

Your runtime beats 36.36 % of cpp submissions.

```cpp
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1) return false;

    int target = sum >> 1;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    if (nums[0] <= target)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i] == j) // 因為這個判斷，所以 dp[0][0] 不用設為 true
                dp[i][j] = true;
            else if (nums[i] < j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
        if (dp[i][target]) return true;
    }

    return false;
}
```

空間優化成一維，從後往前遍歷，避免覆蓋掉DP表格中左面的數據

Your runtime beats 40.53 % of cpp submissions.

```cpp
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1) return false;

    int target = sum >> 1;
    vector<bool> dp(target + 1, false);

    dp[0] = true; // 理解上應該要是false
    if (nums[0] <= target)
        dp[nums[0]] = true;

    for (int i = 1; i < n; ++i) {
        for (int j = target; j >= 0 && nums[i] <= j; --j) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
        if (dp[target]) return true;
    }

    return dp[target];
}
```

最後

```cpp
bool canPartition(vector<int>& nums) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1);

    dp[0] = true; // base case
    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}
```
