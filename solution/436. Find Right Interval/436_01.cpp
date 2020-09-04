class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans;
        map<int, int> m;
        
        for (int i = 0; i < n; i++)
            m[intervals[i][0]] = i;
        
        for (auto& interval : intervals) {
            auto it = m.lower_bound(interval[1]);
            if (it == m.end()) ans.push_back(-1);
            else ans.push_back(it->second);
        }
        
        return ans;
    }
};
