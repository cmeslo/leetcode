class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> l, r;
        int start = newInterval[0];
        int end = newInterval[1];
        
        for (const auto& interval : intervals) {
            if (interval[1] < start) {
                l.push_back(interval);
            } else if (end < interval[0]) {
                r.push_back(interval);
            } else {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }
        
        vector<vector<int>> ans(std::move(l));
        ans.push_back({start, end});
        ans.insert(ans.end(), r.begin(), r.end());
        
        return ans;
    }
};
