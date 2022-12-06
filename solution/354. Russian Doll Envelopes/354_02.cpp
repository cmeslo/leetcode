class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> LIS;
        for (auto& e : envelopes) {
            if (LIS.empty() || LIS.back() < e[1])
                LIS.push_back(e[1]);
            else {
                auto it = lower_bound(LIS.begin(), LIS.end(), e[1]);
                *it = e[1];
            }
        }
        return LIS.size();
    }
};
