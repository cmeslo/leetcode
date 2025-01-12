class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        using pii = pair<int, int >;
        const int n = grid[0].size();
        const vector<int> dir = {0, 1, 0, -1, 0};
        vector<vector<int>> F(n, vector<int>(n, INT_MAX));
        
        queue<pii> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    F[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int y = i + dir[k];
                int x = j + dir[k + 1];
                if (y < 0 || y >= n || x < 0 || x >= n || F[y][x] <= F[i][j] + 1) continue;
                F[y][x] = F[i][j] + 1;
                q.push({y, x});
            }
        }
        
        priority_queue<pii> pq;
        pq.push({F[0][0], 0});
        while (!pq.empty()) {
            auto [f, pos] = pq.top(); pq.pop();
            int i = pos / n, j = pos % n;
            if (i == n - 1 && j == n - 1) return f;
            for (int k = 0; k < 4; ++k) {
                int y = i + dir[k];
                int x = j + dir[k + 1];
                if (y < 0 || y >= n || x < 0 || x >= n || F[y][x] == 0) continue;
                int new_pos = y * n + x;
                int new_f = min(f, F[y][x]);
                F[y][x] = 0;
                pq.push({new_f, new_pos});
            }
        }
        return 0;
    }
};
