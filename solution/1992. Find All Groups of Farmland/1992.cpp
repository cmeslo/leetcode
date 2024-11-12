class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int m = land.size(), n = land[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + land[i-1][j-1];
            }
        }
        
        vector<vector<int>> res;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (land[i-1][j-1] != 1) continue;
                int y = i, x = j;
                for (; y <= m; ++y) {
                    int sum = presum[y][x] - presum[i-1][x] - presum[y][j-1] + presum[i-1][j-1];
                    if (sum != (y - i + 1) * (x - j + 1)) {
                        break;
                    }
                }
                --y;
                for (; x <= n; ++x) {
                    int sum = presum[y][x] - presum[i-1][x] - presum[y][j-1] + presum[i-1][j-1];
                    if (sum != (y - i + 1) * (x - j + 1)) {
                        break;
                    }
                }
                --x;
                
                res.push_back({i-1, j-1, y-1, x-1});
                for (int y1 = i; y1 <= y; ++y1) {
                    for (int x1 = j; x1 <= x; ++x1) {
                        land[y1-1][x1-1] = 2;
                    }
                }
            }
        }
        return res;
    }
};


// 1 0 0
// 0 1 1 <-- y1
// 0 1 1 <-- y2

// 1 2 2
