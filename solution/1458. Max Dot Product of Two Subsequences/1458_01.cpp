class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN/2));
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);
        for (int i = 1; i <= m; ++i)
            dp[i][1] = max(dp[i-1][1], nums1[i] * nums2[1]);
        for (int j = 1; j <= n; ++j)
            dp[1][j] = max(dp[1][j-1], nums1[1] * nums2[j]);

        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = max({
                    dp[i-1][j-1],
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1] + nums1[i]*nums2[j],
                    nums1[i] * nums2[j]
                });
            }
        }
        return dp[m][n];
    }
};


// x x x i
// x x j

// dp[i][j] = max {
//     dp[i-1][j-1],
//     dp[i-1][j],
//     dp[i][j-1],
//     dp[i-1][j-1] + A[i]*B[j],
//     nums1[i] * nums2[j]
// }
