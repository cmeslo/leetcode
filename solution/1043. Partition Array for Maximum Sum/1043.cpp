class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        const int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                mx = max(mx, arr[i - k]);
                dp[i] = max(dp[i], mx * k + dp[i - k]);
            }
        }
        return dp[n];
    }
};

// x x x x x
//     j   i

// dp[i] = max[i:j] * (i-j+1) + dp[j]
