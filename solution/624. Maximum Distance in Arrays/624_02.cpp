class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int mn = arrays[0][0], mx = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, arrays[i].back() - mn);
            res = max(res, mx - arrays[i][0]);
            mx = max(mx, arrays[i].back());
            mn = min(mn, arrays[i][0]);
        }
        return res;
    }
};
