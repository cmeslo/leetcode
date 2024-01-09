class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        
        int ans = 0, i = 0;
        for (int j = 1; j < n; ++j) {
            if (intervals[i][1] <= intervals[j][0])
                i = j;
            else
                ans++;
        }
        return ans;
    }
};


// ____
//     _____
//          ____
// _________
    
