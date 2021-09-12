# 1690. Stone Game VII

## Solution 1: Recursion + memo

```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(begin(stones), end(stones), 0);
        dp.clear();
        dp.resize(n, vector<int>(n));
        return dfs(stones, 0, n - 1, sum);
    }
    
private:
    vector<vector<int>> dp;
    
    int dfs(vector<int>& stones, int l, int r, int sum) {
        if (l == r) return 0;
        if (dp[l][r]) return dp[l][r];
        
        int takeLeft = dfs(stones, l + 1, r, sum - stones[l]);
        int takeRight = dfs(stones, l, r - 1, sum - stones[r]);
        
        return dp[l][r] = max(sum - stones[l] - takeLeft,
                              sum - stones[r] - takeRight);
    }
};
```
