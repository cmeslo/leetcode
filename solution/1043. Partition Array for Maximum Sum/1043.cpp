class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        arr.insert(arr.begin(), 0);
        
        vector<vector<int>> mx(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            mx[i][i] = arr[i];
            for (int j = i-1; j >= 1; --j) {
                mx[j][i] = max(mx[j + 1][i], arr[j]);
            }
        }
        
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = max(1, i-k+1); j <= i; ++j) {
                dp[i] = max(dp[i], mx[j][i] * (i-j+1) + dp[j-1]);
            }
        }
        return dp[n];
    }
};

// x x x x x
//     j   i

// dp[i] = max[i:j] * (i-j+1) + dp[j]
