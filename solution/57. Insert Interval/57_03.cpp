class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> ans;
        
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < start) {
            ans.push_back(intervals[i++]);
        }
        
        while (i < n && !(end < intervals[i][0])) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back({start, end});
        
        while (i < n) {
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};
