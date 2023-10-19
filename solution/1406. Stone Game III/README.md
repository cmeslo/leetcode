# 1406. Stone Game III

## Solution 1: Recursion + memo

### 寫法一

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        this->n = stoneValue.size();
        fill(begin(memo), begin(memo) + n, INT_MIN);
        
        for (int i = n - 1; i >= 0; --i)
            suf[i] = suf[i + 1] + stoneValue[i];
        
        int res = dp(0, stoneValue) - (suf[0] - dp(0, stoneValue));
        if (res > 0)
            return "Alice";
        if (res < 0)
            return "Bob";
        return "Tie";
    }
    
    
private:
    int n;
    int suf[50001];
    int memo[50001];
    
    int dp(int i, vector<int>& stone) {
        if (i >= n) return 0;
        if (memo[i] != INT_MIN) return memo[i];
        
        int sum = 0;
        for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
            sum += stone[i + k - 1];
            memo[i] = max(memo[i], sum + suf[i + k] - dp(i + k, stone));
        }
        return memo[i];
    }
};
```

### 寫法二

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int res = dfs(0, stoneValue);
        if (res > 0)
            return "Alice";
        if (res < 0)
            return "Bob";
        return "Tie";
    }
    
    
private:
    int dp[50001] = {[0 ... 50000] = INT_MIN};
    
    int dfs(int i, vector<int>& stone) {
        if (i >= stone.size()) return 0;
        if (dp[i] != INT_MIN) return dp[i];
        
        int sum = 0;
        for (int k = 1; k <= 3 && i + k - 1 < stone.size(); ++k) {
            sum += stone[i + k - 1];
            dp[i] = max(dp[i], sum - dfs(i + k, stone));
        }
        return dp[i];
    }
};

// [x x] {x x}
```
