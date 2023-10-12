class Solution {
public:
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        expendIslandOne(g);
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << g[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 3)
                    q.push({i, j});
            }
        }
        // cout << q.size() << endl;
        
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= n || x < 0 || x >= n) continue;
                    if (g[y][x] == 1) return step;
                    if (g[y][x] != 0) continue;
                    g[y][x] = 3;
                    q.push({y, x});
                }
            }
            step++;
        }
        return -1;
    }

private:
    vector<int> dirs = {0, -1, 0, 1, 0};
    
    // 把 island 1 變為用 2 標示, 再把邊緣外邊設為 3
    void expendIslandOne(vector<vector<int>>& g) {
        int n = g.size();
        int color = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1) {
                    queue<pair<int, int>> q;
                    g[i][j] = color;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [i, j] = q.front(); q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int y = i + dirs[k];
                            int x = j + dirs[k + 1];
                            if (y < 0 || y >= n || x < 0 || x >= n) continue;
                            if (g[y][x] == 0) g[y][x] = 3;
                            if (g[y][x] != 1) continue;
                            g[y][x] = color;
                            q.push({y, x});
                        }
                    }
                    return;
                }
            }
        }
    }
};

// [1,1,1,1,1],
// [1,0,0,0,1],
// [1,0,1,0,1],
// [1,0,0,0,1],
// [1,1,1,1,1]

// [2,2,2,2,2],
// [2,3,3,3,2],
// [2,3,1,3,2],
// [2,3,3,3,2],
// [2,2,2,2,2]
