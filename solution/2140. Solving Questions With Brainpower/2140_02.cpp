class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            int point = questions[i][0], brain = questions[i][1];
            dp[i] = max(dp[i + 1], point + dp[min(n, i + 1 + brain)]);
        }
        return dp[0];
    }
};

// dp[i] = the maximum points you can earn for the exam at [i:n-1]

// x x x x x x x x
//   i     j
  
// dp[i] = point[i] + dp[min(n, i + 1 + brain[i])]  if solve
// dp[i] = dp[i + 1]  if skip
