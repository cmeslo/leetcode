class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto& banks : accounts)
            res = max(res, accumulate(banks.begin(), banks.end(), 0));
        return res;
    }
};
