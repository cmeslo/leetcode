class Solution {
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1);
        dp[0] = true;
        dp[1] = false;
        dp[2] = A[0] == A[1];
        for (int i = 3; i <= n; ++i) {
            dp[i] = (A[i - 2] == A[i - 1] && dp[i - 2]) ||
                (A[i - 3] == A[i - 1] && A[i - 2] == A[i - 1] && dp[i - 3]) ||
                (A[i - 3] + 2 == A[i - 1] && A[i - 2] + 1 == A[i - 1] && dp[i - 3]);
        }
        return dp[n];
    }
};

// dp[i] = A[i - 1] == A[i] && dp[i - 2]
//         A[i - 2] == A[i] && A[i - 1] == A[i] && dp[i - 3]
//         A[i - 2] + 2 == A[i] && A[i - 1] + 1 == A[i] && dp[i - 3]
        
