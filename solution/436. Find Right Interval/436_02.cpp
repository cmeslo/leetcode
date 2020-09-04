class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> sorted(n); // {start, index}
        
        for (int i = 0; i < n; ++i)
            sorted[i] = {intervals[i][0], i};
        
        sort(sorted.begin(), sorted.end());
        
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i)
            ans[i] = binary_search(sorted, intervals[i][1]);
        
        return ans;
    }
    
private:
    int binary_search(vector<pair<int, int>>& sorted, int end) {
        if (sorted.back().first < end) return -1;
        
        int l = 0, r = sorted.size();
        while (l < r) { // lower_bound
            int mid = l + (r - l) / 2;
            int mid_start = sorted[mid].first;
            if (mid_start < end) l = mid + 1;
            else r = mid;
        }
        
        return sorted[l].second;
    }
};
