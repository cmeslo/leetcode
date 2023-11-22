class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        arr1.insert(arr1.begin(), 0);
        sort(arr2.begin(), arr2.end());
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= i; ++k) {
                if (dp[i - 1][k] < arr1[i])
                    dp[i][k] = min(dp[i][k], arr1[i]);
                
                if (k >= 1) {
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][k - 1]);
                    if (it != arr2.end())
                        dp[i][k] = min(dp[i][k], *it);
                }
            }
        }
        
        for (int k = 0; k <= n; ++k)
            if (dp[n][k] != INT_MAX)
                return k;
        return -1;
    }
};

// dp[i][k] = 
    
// if dp[i-1][k] < arr1[i]
//     dp[i][k] = arr1[i]

// if dp[i-1][k] < replace(arr1[i])
//     dp[i][k] = replace(arr1[i])
