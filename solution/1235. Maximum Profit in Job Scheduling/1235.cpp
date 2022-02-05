class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });
        
        map<int, int> dp; // {endTime, profit}
        dp[-1] = 0;
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            auto it = dp.upper_bound(jobs[i][0]);
            cur = max(pre, prev(it)->second + jobs[i][2]);
            dp[jobs[i][1]] = pre = cur;
        }
        return pre;
    }
};


// ------
//    ----j
//      -------
//          -------i

// definition 1 (may TLE, not working):
// dp[i] = max{dp[j] + profit[i]} for j = ...
// loop -> n^2

// definition 2:
// dp[t] := by the time t, the max profit we can got.
// dp[i] = max(dp[j] + val[i], dp[i-1])
