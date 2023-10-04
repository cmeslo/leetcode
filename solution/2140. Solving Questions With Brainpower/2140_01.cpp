class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        using ll = long long;
        int n = questions.size();
        vector<ll> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            int a = min(n, i + 1 + questions[i][1]); // solve
            dp[a] = max(dp[a], dp[i] + questions[i][0]);
            
            int b = min(n, i + 1); // skip
            dp[b] = max(dp[b], dp[i]);
        }
        return dp[n];
    }
};

// dp[i] = the maximum points you can earn for the exam at [0:i]

// dp[i + 1 + brainPower[i]] = max{point[i] + dp[i]} if solve
// dp[i + 1] = max{dp[i]} if skip
