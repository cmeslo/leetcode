class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int n = g.size(), res = 0;
        map<vector<int>, int> m;
        for (int j = 0; j < n; ++j) {
            vector<int> col;
            for (int i = 0; i < n; ++i)
                col.push_back(g[i][j]);
            auto it = m.find(col);
            if (it == m.end())
                m.emplace(move(col), 1);
            else
                ++it->second;
        }
        for (const auto& row : g)
            if (m.count(row))
                res += m[row];
        return res;
    }
};
