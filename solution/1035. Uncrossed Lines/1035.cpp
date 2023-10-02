class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (nums1[i] == nums2[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};


//  2,5,1,2,5
//    |  \ \
// 10,5,2,1,5,2
     
// dp[i][j] = dp[i-1][j-1] + (A[i] == B[j])
