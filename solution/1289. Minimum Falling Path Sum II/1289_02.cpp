class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int m = A.size(), n = A[0].size();
        
        vector<int> prev = A[0], dp = A[0];
        for (int i = 1; i < m; ++i) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }
            
            for (int j = 0; j < n; ++j)
                dp[j] = A[i][j] + (prev[j] == min1 ? min2 : min1);
            
            swap(prev, dp);
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j)
            res = min(res, prev[j]);
        return res;
    }
};
