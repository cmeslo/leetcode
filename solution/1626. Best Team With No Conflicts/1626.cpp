class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {ages[i], scores[i]};
        }
        sort(A.begin(), A.end());
        
        int res = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = A[i].second;
            for (int j = 0; j < i; ++j) {
                if (A[j].second <= A[i].second)
                    dp[i] = max(dp[i], dp[j] + A[i].second);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
