class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        res.push_back({});
        for (int x : nums) {
            if (res.back().empty()) {
                res.back().push_back(x);
                continue;
            }
            if (res.back().size() < 3 && x - res.back()[0] <= k) {
                res.back().push_back(x);
            } else {
                if (res.back().size() < 3) return {};
                res.push_back({x});
            }
        }
        if (res.back().size() < 3) return {};
        return res;
    }
};
