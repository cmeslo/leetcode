class Solution {
public:
    double new21Game(int n, int k, int w) {
        vector<double> dp(k + w);
        double s = 0;
        for (int i = k; i < k + w; ++i) {
            dp[i] = i <= n ? 1 : 0;
            s += dp[i];
        }
        
        for (int i = k - 1; i >= 0; --i) {
            dp[i] = s / w;
            s -= dp[i + w];
            s += dp[i];
        }
        return dp[0];
    }
};
