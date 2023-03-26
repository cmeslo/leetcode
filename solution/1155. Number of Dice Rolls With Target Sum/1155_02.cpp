class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memo.resize(31, vector<int>(1001, -1));
        return dp(n, k, target);
    }
    
    const int M = 1e9 + 7;
    vector<vector<int>> memo;
    int dp(int n, int k, int target) {
        if (n <= 0 || target <= 0) return n == 0 && target == 0;
        if (memo[n][target] != -1) return memo[n][target];
        int res = 0;
        for (int j = 1; j <= k; ++j) {
            res = (res + dp(n - 1, k, target - j)) % M;
        }
        return memo[n][target] = res;
    }
};
