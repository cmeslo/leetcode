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
