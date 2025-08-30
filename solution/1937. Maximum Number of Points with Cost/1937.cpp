class Solution {
public:
    long long maxPoints(vector<vector<int>>& A) {
        using ll = long long;
        int m = A.size(), n = A[0].size();
        
        vector<ll> dp(n);
        for (int i = 0; i < m; ++i) {
            auto pre = dp;
            ll mx = INT_MIN;
            for (int j = 0; j < n; ++j) {
                mx = max(mx, pre[j] + j);
                dp[j] = max(dp[j], mx + A[i][j] - j);
            }
            mx = INT_MIN;
            for (int j = n - 1; j >= 0; --j) {
                mx = max(mx, pre[j] - j);
                dp[j] = max(dp[j], mx + A[i][j] + j);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// dp[i][j] = dp[i - 1][k] + A[i][j] - abs(j - k)
// O(m * n * n) => failed


// abs(j - k) -> j - k >= 0, j - k <= 0;

// j - k >= 0, k <= j
// dp[i][j] = dp[i - 1][k] + A[i][j] + k - j,   k = 0,1,2,...,j
// dp[i][j] = dp[i - 1][k] + k + A[i][j] - j

// j - k <= 0, j <= k
// dp[i][j] = dp[i - 1][k] + A[i][j] - k + j,   k = j, j+1 ,j+2 ,... ,n-1
// dp[i][j] = dp[i - 1][k] - k + A[i][j] + j
