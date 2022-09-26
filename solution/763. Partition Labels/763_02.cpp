class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<pair<int, int>> intervals(26, {n, -1});
        for (int i = 0; i < n; ++i) {
            auto& x = intervals[s[i] - 'a'];
            x.first = min(x.first, i);
            x.second = max(x.second, i);
        }
        
        vector<pair<int, int>> res;
        for (char& c : s) {
            auto& x = intervals[c - 'a'];
            if (res.empty() || res.back().second < x.first)
                res.push_back(x);
            else
                res.back().second = max(res.back().second, x.second);
        }
        vector<int> ans;
        for (auto [l, r] : res)
            ans.push_back(r - l + 1);
        return ans;
    }
};

// ababcbacadefegde
// 0123456789

// a: 0, 2, ... 8
// b: 1, ..., 5
// c: 4, 7
// d: 9, 14
// e: 10, 15

