class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto old = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < old.size(); ++i)
            res += old[i] != heights[i];
        return res;
    }
};
