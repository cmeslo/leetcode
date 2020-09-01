class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> isTravellingDay(days.back() + 1, false);
        vector<int> dp(days.back() + 1);
        
        for (int day : days) isTravellingDay[day] = true;
        dp[0] = 0;
        
        for (int i = 1; i < dp.size(); ++i) {
            if (!isTravellingDay[i]) {
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = dp[i-1] + costs[0];
            dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);
        }
        
        return dp.back();
    }
};
