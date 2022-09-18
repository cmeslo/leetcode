class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> gain(n);
        for (int x : nums)
            gain[x] += x;
        
        vector<int> dp(n);
        dp[1] = gain[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], gain[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};
