class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        mem.resize(n, vector<int>(k + 1, -1));
        return dp(piles, n - 1, k);
    }
    
private:
    vector<vector<int>> mem;
    
    int dp(vector<vector<int>>& P, int i, int k) {
        if (i < 0 || k == 0) return 0;
        if (mem[i][k] != -1) return mem[i][k];
        
        int res = dp(P, i - 1, k), sum = 0;
        
        int limit = min((int)P[i].size(), k);
        for (int j = 0; j < limit; ++j) {
            sum += P[i][j];
            res = max(res, dp(P, i - 1, k - 1 - j) + sum);
        }
        
        return mem[i][k] = res;
    }
};


// dp[2][2] = dp[1][0]
// dp[2][1] = dp[1][1]
// dp[2][0] = dp[1][2]

// dp[i][j] = dp[i - 1][k - j]
