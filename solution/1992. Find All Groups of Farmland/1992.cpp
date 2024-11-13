class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int m = land.size(), n = land[0].size();
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] != 1) continue;
                int y = i, x = j;
                for (; y < m && land[y][j] == 1; ++y);
                for (; x < n && land[i][x] == 1; ++x);
                --y;
                --x;
                res.push_back({i, j, y, x});
                
                for (int a = i; a <= y; ++a)
                    for (int b = j; b <= x; ++b)
                        land[a][b] = 2;
            }
        }
        return res;
    }
};
