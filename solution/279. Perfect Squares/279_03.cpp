class Solution {
public:
    int numSquares(int n) {
        return dp(n);
    }
    
private:
    int memo[10001];
    
    int dp(int n) {
        int r = sqrt(n);
        if (r * r == n) return 1;
        if (memo[n]) return memo[n];
        
        int res = n;
        for (int i = 1; i * i < n; ++i) {
            res = min(res, dp(i * i) + dp(n - i * i));
        }
        return memo[n] = res;
    }
};


// 12
// 4 + 4 + 4

// dp[12] = dp[8] + dp[4]

// dp[8] = dp[4] + dp[4]

// dp[4] = 1

// 13
// 4 + 9

