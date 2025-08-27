class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int n = arrays.size();
        int res = 0;
        
        vector<pair<int, int>> mx(2);
        mx[0] = mx[1] = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (arrays[i].back() > mx[0].first) {
                swap(mx[0], mx[1]);
                mx[0] = {arrays[i].back(), i};
            } else if (arrays[i].back() > mx[1].first) {
                mx[1] = {arrays[i].back(), i};
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (mx[0].second != i)
                res = max(res, mx[0].first - arrays[i][0]);
            else
                res = max(res, mx[1].first - arrays[i][0]);
        }
        
        return res;
    }
};
