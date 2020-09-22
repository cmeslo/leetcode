class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {     
        int i = 0;
        while (i < intervals.size() && intervals[i][0] < newInterval[0]) i++;
        intervals.insert(intervals.begin() + i, newInterval);
        
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        
        return ans;
    }
};
