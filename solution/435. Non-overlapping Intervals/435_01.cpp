class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        
        auto& prev = intervals[0];
        for (int i = 1; i < n; i++) {
            auto& next = intervals[i];
            if (prev[1] <= next[0]) prev = next;
            else ans++;
        }
        
        return ans;
    }
};
