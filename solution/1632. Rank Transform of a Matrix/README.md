# 1632. Rank Transform of a Matrix

## Solution: Union Find

```cpp
class DSU {
public:
    DSU(int n): p_(n, -1) {};
    
    int find(int y) {
        if (p_[y] == -1)
            return y;
        return p_[y] = find(p_[y]);
    }
    
    void merge(int y, int x) {
        int ry = find(y);
        int rx = find(x);
        if (ry != rx) p_[ry] = rx;
    }
    
private:
    vector<int> p_;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rank_rows(m), rank_cols(n);
        
        map<int, vector<pair<int, int>>> group;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                group[matrix[i][j]].emplace_back(i, j);
        
        vector<vector<int>> ans(m, vector<int>(n));
        for (auto& [val, members] : group) {
            DSU dsu(m + n);
            for (auto [y, x] : members)
                dsu.merge(y, x + m);
            vector<vector<pair<int, int>>> cc(m + n);
            for (auto [y, x] : members)
                cc[dsu.find(y)].emplace_back(y, x);
            for (auto& ps : cc) {
                int rank = 1;
                for (auto [y, x] : ps)
                    rank = max(rank, max(rank_rows[y], rank_cols[x]) + 1);
                for (auto [y, x] : ps)
                    rank_rows[y] = rank_cols[x] = ans[y][x] = rank;
            }
        }
        return ans;
    }
};
```
