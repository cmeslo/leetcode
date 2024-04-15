class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> X;
        for (auto& p : points)
            X.insert(p[0]);
        
        int res = 0, pre = *X.begin();
        for (auto& x : X) {
            res = max(res, x - pre);
            pre = x;
        }
        return res;
    }
};
