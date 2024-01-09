class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        
        auto& prev = intervals[0];
        for (int i = 1; i < n; i++) {
            auto& next = intervals[i];
            if (prev[1] <= next[0]) {
                prev = next;
            } else {
                ans++;
                prev = prev[1] < next[1] ? prev : next;
            }
        }
        
        return ans;
    }
};
