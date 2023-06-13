class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        intervals.insert(it, newInterval);

        vector<vector<int>> res;
        for (auto& in : intervals) {
            if (!res.empty() && res.back()[1] >= in[0]) {
                res.back()[1] = max(res.back()[1], in[1]);
            } else {
                res.push_back(in);
            }
        }
        
        return res;
    }
};
