class Solution {
public:
    int maxValue(vector<vector<int>>& E, int k) {
        const int n = E.size();
        sort(begin(E), end(E), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        E.insert(E.begin(), {0, 0, 0});
        
        vector<int> A(n + 1);
        for (int i = 0; i <= n; ++i)
            A[i] = E[i][1];
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            int j = lower_bound(A.begin(), A.end(), E[i][0]) - 1 - A.begin();
            for (int t = 1; t <= k; ++t) {
                dp[i][t] = max(dp[i - 1][t], dp[j][t - 1] + E[i][2]);
            }
        }
        return dp[n][k];
    }
};

// dp[i][t] = dp[i - 1][t],
//            dp[j][t - 1] + value[i] 對於上一個不相交的 j

// ___
//   ______
//      _______
//       __________
