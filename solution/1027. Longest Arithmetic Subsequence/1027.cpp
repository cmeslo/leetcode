class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int n = nums.size();
        int mx = 500, res = 0;
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j] + mx;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                res = max(res, dp[i][d]);
            }
        }
        return res;
    }
};

// [1,3,5,8,10,15,20]

// 3 5 3
